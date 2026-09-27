#include <cstdlib>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>

using namespace std::chrono;

void perfect() {
    system("clear");
    std::cout << "1" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("clear");
    std::cout << "2" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("clear");
    std::cout << "3" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("clear");
    std::string name;
    std::cout << "hello i am bot what is your name?\n\n> ";
    std::getline(std::cin, name);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("clear");
    std::cout << "hello " << name << " nice to meet you!";
}

int main()
{
    perfect();
    return 0;
    /**
    there are more functions of cstdlib
    exit();
    rand();
    abs();
    atoi(); converts c-style string into integer
    atof(); converts c-style string into float number
    **/
}
