#define WASM_EXPORT __attribute__((visibility("default")))
#include <iostream>
using namespace std;
WASM_EXPORT

int main()
{    
    int number;

    cout << "Enter an integer: ";
    cin >> number;

    cout << "You entered " << number;    
    return 0;
}