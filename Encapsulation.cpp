#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
    string name;
    int age;
    
    private:
    string gfName;
    
    public:
    Person(string name, int age, string gfName) 
    {
        this-> name = name;
        this-> age = age;
        this-> gfName = gfName;
    }
    
    public:
    string getGF() {
        return gfName;
    }
    
    void setterGF(string gfName) {
        this-> gfName = gfName;
    }
};

int main() {
    Person p1("mahad", 15, "ayesha");
    p1.setterGF("hafsa");
    
    cout << p1.getGF();;
    return 0;
}