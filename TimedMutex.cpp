#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std::literals;  // for 10ms, 20ms etc.

int val = 0;
std::timed_mutex mtx;           // Fixed: was "time_mutex"

void func(int i) {
    // Try to acquire the lock within 10 milliseconds
    if (mtx.try_lock_for(10ms)) {
        ++val;                                   // Critical section
        std::this_thread::sleep_for(9ms);       // Simulate work
        std::cout << i << " in critical section\n";
        mtx.unlock();
    } else {
        std::cout << i << " does not in critical section\n";
    }
}

int main() {
    std::thread t1(func, 1);
    std::thread t2(func, 2);

    t1.join();
    t2.join();

    std::cout << val << '\n';    // Now prints the final value
    return 0;
}
