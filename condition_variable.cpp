#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

/*
condition variables are the concept which helps you 
to notify a thread or start a desired thread with condition which is usefull
look down below!
*/

mutex mtx;
condition_variable cv;
int balance = 0;

void withdraw(int amount) {//consumer
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, [&]{ return balance >= amount; });
    balance -= amount;
    cout << "Withdrew " << amount << ", new balance " << balance << "\n";
}

void deposit(int amount) {//producer
    lock_guard<mutex> lock(mtx);
    balance += amount;
    cout << "Deposited " << amount << ", balance " << balance << "\n";
    cv.notify_one();
}

int main() {
    thread t1(withdraw, 300);
    thread t2(deposit, 500);
    t1.join();
    t2.join();
}
