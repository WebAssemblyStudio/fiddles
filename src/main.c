#define WASM_EXPORT __attribute__((visibility("default")))
#define u32 unsigned int
#define i32 int
#define u8 unsigned char
#define i8 char
u32 POLY=0xEDB88320;
WASM_EXPORT u32 table[256];
WASM_EXPORT void init(){
  for(u32 i=0;i<256;i++){
    u32 j=i;
    for(u8 _=0;_<8;_++){
      j=j&1?j>>1^POLY:j>>1;
    }
    table[i]=j;
  }
}
u8 crc_index;
u32 crc32(u8* str,u8 len){
  u32 crc=~0;
  for(u8 i=0;i<len;i++){
    crc_index=(crc^str[i])&0xFF;
    crc=crc>>8^table[crc_index];
  }
  return crc;
}
u8 lastIndex(u8 crc){
  for(u32 i=0;i<256;i++){
    if(crc==table[i]>>24){return i;}
  }
  return 0;
}
union{
  u32 value;
  u8 bytes[4];
}indexes;
WASM_EXPORT u32 getIndexes(u32 crc){
  for(u8 i=3,j=0;j<4;i--,j++){
    u8 crc_index=indexes.bytes[j]=lastIndex(crc>>(i<<3));
    u32 value=table[crc_index];
    crc^=value>>(j<<3);
  }
  return indexes.value;
}
u8 itoa(u32 unum,u8* str){
  u8 i=0;
  do{
    str[i++]=unum%10+48;
    unum/=10;
  }while(unum);
  for(u8 j=0;j<=(i-1)/2;j++){
    u8 temp=str[j];
    str[j]=str[i-1-j];
    str[i-1-j]=temp;
  }
  return i;
}
u8 str[10];
WASM_EXPORT i32 check(i32 i,u32 indexes_value){
  u8 len=itoa(i,str);
  u32 crc=crc32(str,len);
  indexes.value=indexes_value;
  if(crc_index!=indexes.bytes[3]){
    return -1;
  }
  i32 low=0;
  for(i8 i=2;i>-1;i--){
    u8 num=(crc&0xFF)^indexes.bytes[i];
    if(num<48||num>57){return -1;}
    low=low<<4|(num-48);
    crc=crc>>8^table[indexes.bytes[i]];
  }
  return low;
}
WASM_EXPORT i32 findIndex(u32 crc,u32 indexes,i32 begin,i32 end){
  for(i32 i=begin;i<end;i++){
    i32 low=check(i,indexes);
    if(low>=0){return i;}
  }
  return -1;
}