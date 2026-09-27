#include <iostream>
#include <map>

using namespace std;

// Create a map that will store strings and integers
int main() {
    map<string, int> people = {{"John", 32}, {"Adele", 45}, {"Bob", 29}};
    /*    
        to access the map use at()
        to add a element so use insert()
        to delete one element use erase()
        to delete whole use clear()
        
    */
    //Loop through the map with an iterator
    for (auto it = people.begin(); it != people.end(); ++it) {
        cout << it->first << " is: " << it->second << "\n";
    }
    return 0;
}  
