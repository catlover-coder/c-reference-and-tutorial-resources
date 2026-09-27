#include <iostream>
#include <utility>

void process(int&) {
    std::cout << "lvalue\n";
}

void process(int&&) {
    std::cout << "rvalue\n";
}

template <typename T>
void wrapper(T&& value) {
    process(std::forward<T>(value));
}

int main() {
    int x = 10;

    wrapper(x);      // lvalue
    wrapper(20);     // rvalue

    return 0;
}
