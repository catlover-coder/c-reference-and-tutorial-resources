#include <iostream>
#include <string>

using namespace std;

namespace RTTIExample {
    class Example {
        
        public:
        string msg;
        
        Example() : msg("you wrote nothing") {}
        
        Example(string m) : msg(m) {}
        
        string printExample() { return msg; }
        
    };
}

using namespace RTTIExample;

int main() {
    Example A;
    Example B("Hello, World!");
    
    cout << A.printExample() << endl;
    cout << B.printExample() << endl;
    return 0;
}
