#define WASM_EXPORT __attribute__((visibility("default")))

WASM_EXPORT
// reading a text file
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

WASM_EXPORT string rread (const char* v) {
  string line;
  stringstream value;
  ifstream myfile ("example.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      value << line;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 

  return value.str().c_str();
}

WASM_EXPORT int main() {
  cout << "main()\n";
  return 0;
}