#include <iostream>

// 1. Unary Left Fold: (((a + b) + c) + d)
template <typename... Args>
auto sum_left(Args... args) {
    return (... + args);
}

// 2. Unary Right Fold: (a + (b + (c + d)))
template <typename... Args>
auto sum_right(Args... args) {
    return (args + ...);
}

// 3. Binary Left Fold: ((((100 + a) + b) + c) + d)
template <typename... Args>
auto sum_from_100(Args... args) {
    return (100 + ... + args);
}

// 4. Binary Right Fold: (a + (b + (c + (d + 100))))
template <typename... Args>
auto sum_add_100_at_end(Args... args) {
    return (args + ... + 100);
}

int main() {
    // Unary Folds
    std::cout << "sum_left(1, 2, 3, 4): " << sum_left(1, 2, 3, 4) << "\n";   // Output: 10
    
    // Binary Folds with initial value 100
    std::cout << "sum_from_100(1, 2, 3): " << sum_from_100(1, 2, 3) << "\n"; // Output: 106

    // Binary Folds with empty packs gracefully fallback to 'init'
    std::cout << "sum_from_100(): "        << sum_from_100()        << "\n"; // Output: 100
}
