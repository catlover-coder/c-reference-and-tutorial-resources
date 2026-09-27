#include <cstdlib>
#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void move_extension {
	for (int i = 0; i< 5; i++) {
		if () {
			
		}
	}
}

char map[5][43] = {
    "R..............XXXXXX..................",
    "...AAAA............CCCC......DD........",
    "...AAAA...BB.......CC......DDDDDD......",
    "...AA.....BBBB.....CC.......DDD........",
    "..........BBBB........................Y"
};

void interface() {
    cout << "R = robot, Y = delivery\n\n" << endl;
    for (int i = 0; i < 5; i++) {
        std::cout << map[i] << '\n';
    }
}

void move(string &move) {
    ofstream m("moves.txt", ios::app);
    if(move == "A") {
    	
    }
}

int main() {
    interface();
    return 0;
}