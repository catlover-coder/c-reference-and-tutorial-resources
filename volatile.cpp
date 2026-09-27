#include <iostream>

volatile int flag = 0;  // volatile tells compiler: flag can change unexpectedly

int main() {
    while (flag == 0) {
        // Without volatile, compiler might assume flag never changes
        // and optimize away the read again, causing infinite loop.
    }
    std::cout << "Flag changed, exiting.\n";
    return 0;
}
