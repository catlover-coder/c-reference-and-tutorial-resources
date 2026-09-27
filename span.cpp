#include <iostream>
#include <span>

void print(std::span<int> numbers) {
    for (int number : numbers) {
        std::cout << number << ' ';
    }
    std::cout << '\n';
}

int main() {
    int numbers[] = {10, 20, 30, 40};
    print(numbers);
    return 0;
}
