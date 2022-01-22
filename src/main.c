#define WASM_EXPORT __attribute__((visibility("default")))


#include <vector>
#include <string>
#include <iostream>
#include <cstring>

WASM_EXPORT
	const char* gencode(std::string str);

WASM_EXPORT
	const char* gendecode(std::string str);

const char* ca;

const char* convertToChar(std::string str) {

	char* ca = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), ca);
	ca[str.size()] = '\0';
	return ca;
}

std::string conv_char_to_string(const char* a) {
	std::string s;
	for (int i = 0; a[i] != '\0'; ++i)
		s += a[i];

	return s;
}

std::string reveter(std::string str) {
	std::string result;
	for (int n = str.length() - 1; n >= 0; n--) {
		result.push_back(str[n]);
	}

	return result;
}

std::string embaralhar(std::string str) {
	int tamanho = str.length();
	int divisor = 2;
	std::string part1;
	std::string part2;
	std::string inicio;
	std::string fim;
	int pedaco = tamanho / 2;
	part1 = str.substr(0, pedaco);
	part2 = str.substr(pedaco,str.length()-pedaco);
	inicio = reveter(part1);
	fim = reveter(part2);
	return inicio + fim;

}

std::string desembaralhar(std::string str) {
	int tamanho = str.length();
	int divisor = 2;
	std::string part1;
	std::string part2;
	std::string inicio;
	std::string fim;
	int pedaco = tamanho / 2;
	part1 = str.substr(0, pedaco);
	part2 = str.substr(pedaco, str.length() - pedaco);
	inicio = reveter(part1);
	fim = reveter(part2);
	return inicio + fim;
}
const char* gencode(std::string in) {

  std::string out;

  int val = 0, valb = -6;
  for (char c : in) {
    val = (val << 8) + c;
    valb += 8; 
    while (valb >= 0) {
      out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[(val>>valb)&0x3F]);
      valb -= 6;
    }
  }
  if (valb>-6) out.push_back("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[((val<<8)>>(valb+8))&0x3F]);
  while (out.size()%4) out.push_back('=');
 
  const char* retorno = convertToChar(embaralhar(out));
  delete(ca);
  return retorno;
}

const char* gendecode(std::string str) {

  std::string in = desembaralhar(str);
  std::string out;

  std::vector<int> T(256,-1);
  for (int i=0; i<64; i++){
    T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;
  }

  int val=0, valb=-8;
  for (char c : in) {
    if (T[c] == -1) break;
    val = (val << 6) + T[c];
    valb += 6;
    if (valb >= 0) {
      out.push_back(char((val>>valb)&0xFF));
      valb -= 8;
    }
  }
  
  const char* retorno = convertToChar(desembaralhar(desembaralhar(out)));
  delete(ca);
  return retorno;
}

