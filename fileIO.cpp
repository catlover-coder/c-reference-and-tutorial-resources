#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;
        
int main() {
    //writing to file
    ofstream fileW("sampleFile.txt", ios::app);
    string name;
    string yesNo;
    
    cout << "==== writing to file ====\n\n";
    
    while(true) {
        cout << "what is your name: ";
        getline(cin, name);
        
        cout << endl;
    
        fileW << name << endl;
        
        cout << "want to write again[y/n]: ";
        getline(cin, yesNo);
        
        cout << endl;
        
        if(yesNo == "n") {
            break;
        }
    }
    
    fileW.close();
    
    cout << '\n';
    
    //reading to file
    ifstream fileR("sampleFile.txt");
    string lines;
    
    cout << "==== reading to file ====\n\n";
    
    while(getline(fileR, lines)) {
        cout << lines << endl;
    }
    
    fileR.close();
    
    string filename = "sampleFile.txt";
    // ... later ...
    if (remove(filename.c_str()) == 0) {// .c_str() converts string to const char*
        cout << "\nFile deleted successfully.\n";
    } else {
        cout << "\nError deleting file.\n";
    }
    return 0;
}
