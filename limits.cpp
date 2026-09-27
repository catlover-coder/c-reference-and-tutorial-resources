#include <iostream>
#include <limits>

int main() {
    std::cout << "int min: " << std::numeric_limits<int>::min() << '\n';
    std::cout << "int max: " << std::numeric_limits<int>::max() << '\n';

    std::cout << "double max: " << std::numeric_limits<double>::max() << '\n';
    
    /**
    
    Patterns:
    std::numeric_limits<T>::min();
    std::numeric_limits<T>::max();
    std::numeric_limits<T>::lowest();
    
    **/

    return 0;
}
