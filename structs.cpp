#include <iostream>
#include <string>
using namespace std;

//lesson structs 
struct student {
    string name;
    int age;
    int Class;
};

int main() {
    
    student student1;
    student1.name = "mahad";
    student1.age = 15;
    student1.Class = 9;
    
    cout << student1.name << "\n";
    cout << student1.age << "\n";
    cout << student1.Class << "\n";    
    
    return 0;
}