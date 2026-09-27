#include <iostream>

using namespace std;

class interface {
    public://declares a pure virtual function(an extansion of function)
        virtual void printH() = 0; 
};

class Class : public interface
{
    public://the body of that virtual fuction
    //without virtual you can not override this
        virtual void printH() {
            cout << "Hello, World!";
        }
};

int main() {
    Class c;
    c.printH();
}