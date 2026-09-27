#include <iostream>
#include <any>
#include <string>

int main() {
    std::any data;

    data = 42;

    std::cout << std::any_cast<int>(data) << '\n';

    data = std::string("Hello");

    std::cout << std::any_cast<std::string>(data) << '\n';

    return 0;
}
