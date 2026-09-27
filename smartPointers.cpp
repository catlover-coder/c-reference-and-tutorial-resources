#include <iostream>
#include <memory>
#include <string>

using namespace std;

int main() {
    auto vr = make_unique<string>("mahad");
    auto vr2 = make_shared<int>(15);
    
    cout << "I am " << *vr << " and i am " << *vr2 << " years old!!!";
    return 0;
}
