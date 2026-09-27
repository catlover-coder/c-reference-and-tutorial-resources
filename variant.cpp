#include <iostream>
#include <variant>
#include <string>

int main() {
    std::variant<int, float, std::string> data;

    data = 42;
    std::cout << std::get<int>(data) << '\n';

    data = 3.14f;
    std::cout << std::get<float>(data) << '\n';

    data = "Hello";
    std::cout << std::get<std::string>(data) << '\n';

    return 0;
}
