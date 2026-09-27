#include <iostream>

int main() {
    // Stack allocation
    int stackVar = 10;          // automatic, goes out of scope at } 
    
    // Heap allocation
    int* heapVar = new int(20); // manual, must delete
    std::cout << stackVar << " " << *heapVar << std::endl;
    
    delete heapVar;             // prevent memory leak
    return 0;
}