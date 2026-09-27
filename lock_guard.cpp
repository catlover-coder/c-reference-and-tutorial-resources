#include <iostream>
#include <mutex>
#include <thread>

std::mutex mtx;
int shared_data = 0;

void safe_increment() {
    std::lock_guard<std::mutex> guard(mtx); // lock acquired here
    ++shared_data;//we cannot add unlock or lock earlier or after
    // guard goes out of scope → mutex automatically unlocked
}

int main() {
    std::thread t1(safe_increment);
    std::thread t2(safe_increment);
    t1.join(); t2.join();
    std::cout << "shared_data = " << shared_data << '\n';
}
