#include <iostream>
#include <mutex>
#include <thread>

std::recursive_mutex rmtx;
int counter = 0;

void recursive_increment(int depth) {
    if (depth == 0) return;
    rmtx.lock();               // same thread can lock again
    ++counter;
    std::cout << "Depth " << depth << ", counter = " << counter << '\n';
    recursive_increment(depth - 1); // recursive call – re‑locks same mutex
    rmtx.unlock();             // must unlock same number of times
}

int main() {
    std::thread t(recursive_increment, 5);
    t.join();
    // Output shows counter 3, no deadlock
}
