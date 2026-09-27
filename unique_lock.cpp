#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
int counter = 0;

void increment() {
    std::unique_lock<std::mutex> lock(mtx);  // locks immediately
    ++counter;//we can also add unlock or lock earlier or after
    std::cout << "Counter: " << counter << "\n";
    // lock automatically unlocks when leaving scope
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join(); t2.join();
}