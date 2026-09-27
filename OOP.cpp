#include <iostream>
#include <string>

using namespace std;

class Student 
{
    public:
    
    //attributes
    string name;
    int age;
    int rollNo;
    
    //constructer
    Student(string name, int age, int rollNo) 
    {
        this-> name = name;
        this-> age = age;
        this-> rollNo = rollNo;
    }
    
    //methods, functions
    void study() {
       cout << this-> name << " is studying..." << endl;  
    }
    
    void sleeping() {
        cout << this-> name << " is sleeping..." << endl;
    }
    
    void bunk() {
        cout << this-> name << " is bunking..." << endl;
    }
    
    //destructer
    ~Student() 
    {
        cout << "destructor executed!!!";
    }
};

int main() {
    
    Student A = {"mahad", 14, 1};
    
    cout << A.name << endl;
    cout << A.age << endl;
    cout << A.rollNo << endl;
    
    A.study();
    
    return 0;
}