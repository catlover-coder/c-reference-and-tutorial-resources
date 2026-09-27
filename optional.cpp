#include <iostream>
#include <optional>

std::optional<int> get_number(bool available) {
    if (available)
        return 42;

    return std::nullopt;
}

int main() {
    auto result = get_number(true);

    if (result) {
        std::cout << "Value: " << *result << '\n';
    } else {
        std::cout << "No value\n";
    }

    return 0;
}
