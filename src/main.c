
#include <string.h>

#define WASM_EXPORT __attribute__((visibility("default")))
typedef unsigned char byte;

const int Domain = 0;
const int SubDomain = 1;
const int WhiteRule_Domain = 2;
const int WhiteRule_SubDomain = 3;

typedef struct {
  int type;
  int start;
  int length;
  int _1;
} RuleItem;

int matchSubDomain(const char* target,const RuleItem* rule,const char* buf){
  int i = 0;
  const char* src = buf+rule->start;
  for(;;){
    if(strcmp(src,target+i)==0){
      return 1;
    }
    while(target[i]!='\0' && target[i]!='.'){
      i++;
    }
    if(target[i]=='\0'){
        return 0;
    }
    if(target[i]=='.'){
      i++;
    }
  }
}

int matchOne(const char* target,const RuleItem* rule,const char* buf){

  const char* src = buf+rule->start;
  switch(rule->type){
      case Domain:
        if(strcmp(src,target)==0){
          return 1;
        }
        break;
      case SubDomain:
        if(matchSubDomain(target,rule,buf)){
          return 1;
        }
        break;
      case WhiteRule_Domain:
        break;
      case WhiteRule_SubDomain:
        break;
      default:
        break;
    }
  return 0;
}

WASM_EXPORT
int matchAny(const char* target,const byte* items,const int length,const char* buf){
  RuleItem *pRule  = (RuleItem*)items;
  for(int i=0;i<length;i++){
    if(matchOne(target,pRule,buf)==1){
      return 1;
    }
    pRule ++;
  }
  return 0;
}

WASM_EXPORT
int main() {
  return 42;
}
