#include <functional>
#include <iostream>
using namespace std;

inline int square(int a) { return a * a; }// an inline fuction

int add(int a, int b) { return a + b; }

int main() {
    function<int(int,int)> func;   // can hold any callable taking two ints, returning int

    func = add;                         // store a free function
    cout << func(2,3) << "\n";     // 5

    func = [](int x, int y) { return x * y; }; // store a lambda
    cout << func(2,3) << "\n";// 6
    
    cout << square(2) << endl;// 4

    return 0;
}