
#include <iostream>
#include <fstream>

using namespace std;

struct Data {
    int id;
    double value;
};

int main() {
    Data myData = {101, 45.67};

    // Open file in binary mode
    ofstream outFile("example.bin", ios::binary);

    if (outFile.is_open()) {
        // Cast address to char* and provide size
        outFile.write((char*)&myData, sizeof(Data));
        outFile.close();
    }
    
    //we use this to access id and value
    Data loadedData;

    // Open file in binary mode
    ifstream inFile("example.bin", ios::binary);

    if (inFile.is_open()) {
        // Read into the memory address of loadedData
        inFile.read((char*)&loadedData, sizeof(Data));
        inFile.close();

        cout << "ID: " << loadedData.id << ", Value: " << loadedData.value << endl;
    }
    return 0;
}
