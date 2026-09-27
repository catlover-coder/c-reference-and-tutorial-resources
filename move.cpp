#include <iostream>
#include <string>
#include <utility>

int main() {
    std::string first = "Hello";

    std::string second = std::move(first);

    std::cout << second << '\n';

    return 0;
}
