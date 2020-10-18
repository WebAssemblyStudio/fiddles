#include <string>
#include "md5.h"

#define SALTKEY "qplmx2271520zwcm"

std::string sign(std::string str){
  return md5(str + string(SALTKEY));
}

EMSCRIPTEN_BIND(my_module){
  emscripten::function("sign", &sign);
}
