#include <iostream>
#include <thread>
#include <future>

using namespace std;

void calculate(promise<int> p) {
    p.set_value(42);  // fulfill the promise
}

int main() {
    promise<int> prom;
    future<int> fut = prom.get_future();

    thread t(calculate, move(prom));  // promise can't be copied

    cout << "Result: " << fut.get() << "\n";  // blocks until value is set
    t.join();
}
