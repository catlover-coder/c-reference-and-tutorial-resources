#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

void personDetailPrinter(Person person) {
     cout << person.name << '\n';
     cout << person.age;
}

int main() {
    Person person1;
    person1.name = "mahad";
    person1.age = 14;
    
    personDetailPrinter(person1);
    return 0;
}