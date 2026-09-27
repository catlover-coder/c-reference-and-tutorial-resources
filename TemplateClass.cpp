#include <iostream>

using namespace std;

template<typename T>
class Printer {
    public:
    void println(T txt) {
        cout << txt << endl;
    }
    void print(T txt) {
        cout << txt;
    }
};

int main() {
    Printer<string> E;
    Printer<int> D;
    
    E.println("hello world");
    D.println(14);
    return 0;
}
