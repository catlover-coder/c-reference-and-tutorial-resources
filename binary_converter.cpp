#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Convert decimal to hexadecimal using subtraction method
string decimalToHex(int n) {
    if (n == 0) return "0";
    if (n < 0) return "-" + decimalToHex(-n);
    
    // Find largest power of 16 <= n
    int maxPower = 1;
    while (maxPower * 16 <= n && maxPower <= n/16) {
        maxPower *= 16;
    }
    
    char hexDigits[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string hex = "";
    int remaining = n;
    
    // Subtract powers of 16 from highest to lowest
    while (maxPower >= 1) {
        if (remaining >= maxPower) {
            int digit = remaining / maxPower;
            hex += hexDigits[digit];
            remaining -= digit * maxPower;
        } else {
            hex += '0';
        }
        maxPower /= 16;
    }
    
    return hex;
}

string toBinaryBySubtraction(int n) {
    if (n == 0) return "0";
    
    vector<int> powers;
    int p = 1;
    while (p <= n) {
        powers.push_back(p);
        p *= 2;
    }
    
    string binary = "";
    int remaining = n;
    
    for (int i = powers.size() - 1; i >= 0; i--) {
        if (remaining >= powers[i]) {
            binary += '1';
            remaining -= powers[i];
        } else {
            binary += '0';
        }
    }
    
    return binary;
}

void printColored(string text, string color) {
    if (color == "red") cout << "\033[31m";
    else if (color == "green") cout << "\033[32m";
    else if (color == "cyan") cout << "\033[36m";
    cout << text << "\033[0m";
}

int main() {
    int number;
    string yn;
    
    cout << "bot: Which number you want to convert into binary?\nyou: ";
    cin >> number;
    
    printColored(toBinaryBySubtraction(number), "green");
    
    cout << "\nbot: Do you want this number in hexadecimal? (yes/no): ";
    cin >> yn;
    
    if (yn == "yes" || yn == "y" || yn == "Yes") {
        printColored(decimalToHex(number), "cyan");
    } else {
        cout << "\nbot: Okay, goodbye!" << endl;
    }
    
    return 0;
}
