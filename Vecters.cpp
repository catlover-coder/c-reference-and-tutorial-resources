#include <iostream>
#include <vector>

using namespace std;

int main() {
   vector<int> numbers = {1, 2, 3, 4, 5};
   cout << "I am " << numbers[0] << numbers[3] << " years old!" << endl;
   
   numbers[2] = 6;
   
   for (int i; i < 4; i++) {
      cout << numbers[i] << endl;
   }
   return 0;
}
