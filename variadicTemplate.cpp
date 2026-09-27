#include <iostream>

// Base case: stop when no arguments remain
void print() {}

// Recursive case: handle first, then the rest
template<typename T, typename... Rest>

void print(T first, Rest... rest) {
    std::cout << first << '\n';
    print(rest...);   // ← pack expansion: calls print() with the remaining args
}

int main() {
    print(10, 2.5, "hello");  // Output: 10 2.5 hello
}
