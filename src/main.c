#include <stdio.h>
#include <sys/uio.h>

#define WASM_EXPORT __attribute__((visibility("default")))


#define SHA3_512_DIGEST_LENGTH      64    /* 64 bytes = 512 bit / 8           */
#define BIT_TO_BYTE_RATE             8    /* 8 * bit  = byte                  */
#define BYTE_TO_WORD_RATE            8    /* 8 * byte = word                  */
#define BUFF_SIZE                 4096

typedef unsigned char          uint8;
typedef unsigned short int     uint16;
typedef unsigned int           uint32;
typedef unsigned long long int uint64;
typedef uint8  byte;
typedef uint64 word;
typedef uint32 uint;

/*
#if OS_BIT == 64
    typedef unsigned long int      uint64;
#else // OSBIT == 32
    typedef unsigned long long int uint64;
#endif 
*/

static const uint32  n  = 512;         // The width of the digest
static const uint32  w  = 64;          // words = 64 bit = 8 bytes
static const uint8   l  = 6;           // 2^l = w <=> 2^l = 64 <=> l = 6
static const uint8   nr = 12 + 2*6;    // nr = 12 + 2*l = 12 + 2*6 = 24 => The number of rounds
static const uint16  b  = 25*64;       // b = 25*w = 25*64 = 1600 => The width of the permutation
static const uint16  c  = 2*512;       // capacity = 2*n = 2*512 = 1024 bit
static const uint32  r  = 1600 - 1024; // rate = b - c = 1600 - 1024 = 576 bit

static uint64 State[25]; // bytestring State

size_t strlen(const char *s) {
    size_t n = 0;
    while(*s++ != '\0') n++;
    return n;
}

uint8 *slice_array(const uint8 src[], uint8 dist[], uint32 start, uint32 end) {
    uint32 i, j;
    for(i = start, j = 0; i < end; i++, j++) {
        dist[j] = src[i];
    }
    return dist;
}

static void bytes_to_words(uint8 from[], uint32 from_bytesize, uint64 to[]) {
    uint32 i, j;
    
    for(i = 0, j = 0; j < from_bytesize; i++, j += BYTE_TO_WORD_RATE) {
        to[i] =   ((uint64)from[j    ] & 0xff)
                | ((uint64)from[j + 1] & 0xff) <<  8
                | ((uint64)from[j + 2] & 0xff) << 16
                | ((uint64)from[j + 3] & 0xff) << 24
                | ((uint64)from[j + 4] & 0xff) << 32
                | ((uint64)from[j + 5] & 0xff) << 40
                | ((uint64)from[j + 6] & 0xff) << 48
                | ((uint64)from[j + 7] & 0xff) << 56;
    }
}

static void words_to_bytes(uint64 from[], uint8 to[], uint32 to_bytesize) {
    uint32 i, j;
    
    for(i = 0, j = 0; i < to_bytesize; i += BYTE_TO_WORD_RATE, j++) {
        to[i    ] = (uint8)(from[j]      );
        to[i + 1] = (uint8)(from[j] >>  8);
        to[i + 2] = (uint8)(from[j] >> 16);
        to[i + 3] = (uint8)(from[j] >> 24);
        to[i + 4] = (uint8)(from[j] >> 32);
        to[i + 5] = (uint8)(from[j] >> 40);
        to[i + 6] = (uint8)(from[j] >> 48);
        to[i + 7] = (uint8)(from[j] >> 56);
    }
}

/* The round constants RC[i] */
static const uint64 RC[24] = {
    0x0000000000000001ULL, 0x0000000000008082ULL, 
    0x800000000000808AULL, 0x8000000080008000ULL, 
    0x000000000000808BULL, 0x0000000080000001ULL,
    0x8000000080008081ULL, 0x8000000000008009ULL, 
    0x000000000000008AULL, 0x0000000000000088ULL, 
    0x0000000080008009ULL, 0x000000008000000AULL,
    0x000000008000808BULL, 0x800000000000008BULL, 
    0x8000000000008089ULL, 0x8000000000008003ULL, 
    0x8000000000008002ULL, 0x8000000000000080ULL,
    0x000000000000800AULL, 0x800000008000000AULL, 
    0x8000000080008081ULL, 0x8000000000008080ULL, 
    0x0000000080000001ULL, 0x8000000080008008ULL
};

/* The rotation offsets */
static const uint32 rot_ofst[25] = {
     0,  1, 62, 28, 27,
    36, 44,  6, 55, 20,
     3, 10, 43, 25, 39,
    41, 45, 15, 21,  8,
    18,  2, 61, 56, 14
};

// Left-rotates
#define rot(value, shift)                                                      \
    ( ( (value) << (shift) ) | ( (value) >> ( w - (shift) ) ) )

#define IDX(x, y) ( ( (x) % 5 ) + 5*( (y) % 5 ) )

#define IDX2(x) ( ( (x) + 5 ) % 5 )

#define IDX3(x) ( (x) % 5 )

static uint64 *Rnd(uint64 A[25], const uint64 RC) {
    uint64 B[25];
    uint64 C[5];
    uint64 D[5];
    uint32 x, y;
    
    // theta step
    for(x = 0; x < 5; x++) {
        C[x] = A[IDX(x, 0)] ^ A[IDX(x, 1)] ^ A[IDX(x, 2)] ^ A[IDX(x, 3)] ^ A[IDX(x, 4)];
    }
    for(x = 0; x < 5; x++) {
        D[x] = C[IDX2(x-1)] ^ rot(C[IDX3(x+1)], 1);
    }
    for(x = 0; x < 5; x++) {
        for(y = 0; y < 5; y++) {
            A[IDX(x, y)] = A[IDX(x, y)] ^ D[x];
        }
    }
    
    // rho and pai steps
    for(x = 0; x < 5; x++) {
        for(y = 0; y < 5; y++) {
            B[IDX(y, 2*x+3*y)] = rot(A[IDX(x, y)], rot_ofst[IDX(x, y)]);
        }
    }
    
    // chi step
    for(x = 0; x < 5; x++) {
        for(y = 0; y < 5; y++) {
            A[IDX(x, y)] = B[IDX(x, y)] ^ ((~B[IDX(x+1, y)]) & B[IDX(x+2, y)]);
        }
    }
    
    // iota step
    A[IDX(0, 0)] = A[IDX(0, 0)] ^ RC;
    
    return A;
}

static uint64 *keccak_f(uint64 A[25]) {
    uint8 i;
    for(i = 0; i < nr; i++) {
        A = Rnd(A, RC[i]);
    }
    
    return A;
}

extern uint8 *sha3_512(const uint8 msg[], uint32 msg_bytesize, uint8 Z[]) {
    uint32   i, x, y;
    uint32   w_byte_len = w / BIT_TO_BYTE_RATE; //  64/8 =  8 byte
    uint32   r_byte_len = r / BIT_TO_BYTE_RATE; // 576/8 = 72 byte
    uint32   n_byte_len = n / BIT_TO_BYTE_RATE; // 512/8 = 64 byte
    uint64  *S = State; // pointer for bytestring State
    uint8    PB[BUFF_SIZE * w_byte_len];
    uint32   PB_length = 0;
    uint64   PW[BUFF_SIZE];
    uint32   PW_length = 0;
    uint32   padding_size = r_byte_len - (msg_bytesize % r_byte_len);
    uint8    ZB[r_byte_len];
    uint64   ZW[r/w]; // 576 / 64 = 72 / 8 = 9
    
    static uint8 _Z[SHA3_512_DIGEST_LENGTH];
    if (Z == NULL) {
        Z = _Z;
    }
    else {
    }
    
    // buffer over error
    if (msg_bytesize + padding_size > BUFF_SIZE * w_byte_len) {
        fprintf(stderr, "error: message size \"%d bytes\" is huge.\n", msg_bytesize);
        return NULL;
    }
    else {
    }
    
    // Initialization
    for(x = 0; x < 5; x++) {
        for(y = 0; y < 5; y++) {
            S[IDX(x, y)] = 0;
        }
    }
    // copy message
    for(x = 0; x < msg_bytesize; x++) {
        PB[x] = msg[x];
    }
    PB_length = msg_bytesize;
    
    // padding process
    if (PB_length % r_byte_len == r_byte_len - 1) {
        PB[PB_length++] = 0x86;
    }
    else {
        PB[PB_length++] = 0x06;
        while(PB_length % r_byte_len != r_byte_len - 1) PB[PB_length++] = 0x00;
        PB[PB_length++] = 0x80;
    }
    
    // padded message is converted bytes to words
    bytes_to_words(PB, PB_length, PW);
    PW_length = PB_length / BYTE_TO_WORD_RATE;
    
    // Absorbing phase
    for(i = 0; i < PW_length;) { // forall block Pi in P
        for(x = 0; x < r/w; x++) { // forall (x,y) such that x+5*y < r/w : (r/w = r_byte_len / w_byte_len = 72 / 8 = 9)
            S[x] = S[x] ^ PW[i++];
        }
        S = keccak_f(S);
    }
    
    // Squeezing phase
    // Z = empty string
    while(1) { // output is requested
        for(x = 0; x < r/w; x++) { // r/w = r_byte_len / w_byte_len = 72 / 8 = 9
            ZW[x] = S[x]; // forall (x,y) such that x+5*y < r/w
        }
        
        break;
        // S = keccak_f(S);
    }
    
    // squeezing result is converted words to bytes
    words_to_bytes(ZW, ZB, r_byte_len);
    
    (void)slice_array(ZB, Z, 0, n_byte_len);
    
    return Z;
}

#define HASHSTR "The quick brown fox jumps over the lazy dog."

WASM_EXPORT
int main() {
  uint8   digest[SHA3_512_DIGEST_LENGTH];
  uint8  *rtn_pointer;
  uint32  i;

  rtn_pointer = sha3_512((const uint8 *)HASHSTR, strlen(HASHSTR), digest);

  if (rtn_pointer != NULL) {
    printf("input key: %s\n", HASHSTR);
    printf("sha3-512 : ");
    for(i = 0; i < SHA3_512_DIGEST_LENGTH; i++) {
        printf("%02x", rtn_pointer[i]);
    }
    printf("\n");
  }
  else {
    fprintf(stderr, "An error occurred while hashing string.");
    return 1;
  }

  return 0;
}

/* External function that is implemented in JavaScript. */
extern putc_js(char c);

/* Basic implementation of the writev sys call. */ 
WASM_EXPORT
size_t writev_c(int fd, const struct iovec *iov, int iovcnt) {
  size_t cnt = 0;
  for (int i = 0; i < iovcnt; i++) {
    for (int j = 0; j < iov[i].iov_len; j++) {
      putc_js(((char *)iov[i].iov_base)[j]);
    }
    cnt += iov[i].iov_len;
  }
  return cnt;
}