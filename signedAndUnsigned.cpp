#include <iostream>
using namespace std;

int main() {
    int num = 23 ;
    double num2 = static_cast<double>(num);
    
    cout << num2 << endl;
    
    signed int a = -10;      // OK
    unsigned int b = 42;     // positive only
    //b = -5;               // WRONG: wraps around to large number

    cout << a << endl;       // -10
    cout << b << endl;       // 42

    short small = 32767;          // max typical short value
    long big = 1000000L;          // L suffix optional
    long long huge = 9318LL;      // LL suffix

    cout << sizeof(short) << " bytes" << endl;   // usually 2
    cout << sizeof(long) << " bytes" << endl;    // usually 4 or 8
    cout << sizeof(long long) << " bytes" << endl; // usually 8
    return 0;
}