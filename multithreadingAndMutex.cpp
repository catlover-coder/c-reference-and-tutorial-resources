#include <iostream>
#include <cstdio>
#include <thread>
#include <mutex>

using namespace std;

int num = 0;
mutex m;//mutex decleration

void increment() {
    m.lock();//first thread have access to lock first
    num++;
    m.unlock();//after doing the work thread will unlock it for other threads
}

int main() {
    thread t1(increment);
    thread t2(increment);
    
    t1.join();
    t2.join();
    
    printf("%d", num);//prints num value
    
    return 0;
}
