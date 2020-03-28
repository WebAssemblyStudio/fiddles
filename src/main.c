#include <string.h>
#define BUFFER_SIZE (1024 * 1024 * 4)
typedef unsigned char BYTE;
void v_r();
bool v_is_f();
void v_r();
void v_d_v_p();
int v_d_c(unsigned char *buf, int size);


int start_ptr = 0;
int cur_ptr = 0;
int end_ptr = 0;

BYTE buffer[BUFFER_SIZE];

enum Status {
  STATUS_INIT,
  STATUS_HEAD,
  STATUS_PREV_SIZE,
  STATUS_TAG_HEADER,
  STATUS_TAG_DATA
};

struct Tag
{
  int type;
  int size;
};

Tag tag;
Status status = STATUS_INIT;

void v_re()
{
  cur_ptr = 0;
  end_ptr = 0;
  start_ptr = 0;
}

BYTE *v_p_b(int len)
{
  if (end_ptr + len > BUFFER_SIZE) {
    int count = end_ptr - start_ptr;
    memmove(buffer, buffer + start_ptr, count);
    cur_ptr -= start_ptr;
    end_ptr -= start_ptr;
    start_ptr = 0;
  }
  return buffer + end_ptr;
}

int v_d(int len)
{
  v_r();
  int size = cur_ptr - start_ptr;
  start_ptr = cur_ptr;
  return size;
}

bool v_is_f() {
  const unsigned char* data = buffer + start_ptr;
  return data[0] == 0x46 && data[1] == 0x4C && data[2] == 0x56 && data[3] == 0x01;
}

inline int readableSize() {
  return end_ptr - cur_ptr;
}

void v_r()
{
  if (status == STATUS_INIT)
  {
    if (readableSize() >= 13)
    {
      cur_ptr += 13;
      status = STATUS_TAG_HEADER;
      v_r();
    }
  }
  else if (status == STATUS_TAG_HEADER)
  {
    if (readableSize() >= 11)
    {
      tag.type = buffer[cur_ptr];
      tag.size = buffer[cur_ptr + 1] << 16 | buffer[cur_ptr + 2] << 8 | buffer[cur_ptr + 3];
      cur_ptr += 11;
      status = STATUS_TAG_DATA;
      v_r();
    }
  }
  else if (status == STATUS_TAG_DATA)
  {
    if (readableSize() >= tag.size)
    {
      if (tag.type == 9) v_d_v_p();
      cur_ptr += tag.size;
      status = STATUS_PREV_SIZE;
      v_r();
    }
  }
  else if (status == STATUS_PREV_SIZE)
  {
    if (readableSize() >= 4)
    {
      cur_ptr += 4;
      status = STATUS_TAG_HEADER;
      v_r();
    }
  }
}

void v_d_v_p()
{
  unsigned char* data = buffer + cur_ptr;
  int size = tag.size;
  int spec = data[0];
  int codecId = spec & 15;
  if (codecId == 7 || codecId == 12)
  {
    unsigned char packetType = data[1];
    if (packetType == 1)
    {
      v_d_c(data + 5, size - 5);
    }
  }
}

int v_d_c(unsigned char *buf, int size)
{
  unsigned int iLens = size;
    unsigned int uiKey = size;

    char key[4] = {0};
    memcpy(key, &uiKey, sizeof(uiKey));
    if (iLens < 2)
    {
        return -1;
    }

    char Key1 = key[0];
    char Key2 = key[1];
    char Key3 = key[2];
    char Key4 = key[3];

    int iCount = 2;
    for (int i = 0; i < iCount; i++)
    {
        for (int j = iLens - 1; j > 0; j--)
        {
            buf[j] = (buf[j] ^ Key1) - buf[j - 1];
        }

        buf[0] = ((buf[0] ^ Key4) ^ Key3) - Key2;
    }
    return 0;
}