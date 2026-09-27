#include <iostream>
#include <string>

using namespace std;

namespace practice {
    class Outer {
        public:
        string name;
        
        Outer(string n) : name(n) {}
        
        class Inner {
            public:
            void print() { cout << "hello" << endl; }
        };
        
        friend void greetName(Outer& A);
    };
    
    void greetName(Outer& A) {
        cout << "hello " << A.name << endl;
    }
}

using namespace practice;

int main() {
    Outer::Inner I;
    I.print();
    
    string nm;
    cout << "what is your name? ";
    cin >> nm;
    
    Outer B(nm);
    greetName(B);
    return 0;
}
