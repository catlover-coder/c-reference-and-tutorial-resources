#include <iostream>
#include <string>
using namespace std;

struct variable { int AmountOfMoney; };

void deposit(variable &v) {
    cout << "\n\n==== deposit ====\n\n";
    
    cout << "balance: " << v.AmountOfMoney << "$" << endl;
    
    int moneyToDeposit;
    
    cout << "\nEnter amount of money you want to deposit: ";
    cin >> moneyToDeposit;
    
    if (moneyToDeposit < 0) {
        cout << "\nCannot deposit negative amount!\n";
        return;
    }else {
        v.AmountOfMoney += moneyToDeposit;
        cout << '\n' << v.AmountOfMoney << "$ amount of money is added" << endl;
    }
}

void withdraw(variable &v) {
    cout << "\n\n==== withdraw ====\n\n";
    cout << "balance: " << v.AmountOfMoney << "$" << endl;

    int minusAmount;
    cout << "\nEnter amount to withdraw: ";
    cin >> minusAmount;

    if (minusAmount > v.AmountOfMoney) {
        cout << "\nInsufficient funds! Withdrawal cancelled.\n";
    }else {
        v.AmountOfMoney -= minusAmount;
        cout << '\n' << minusAmount << "$ withdrawn. balance: " << v.AmountOfMoney << "$" << endl;
    }
}

void sendMoney(variable &d) {
    cout << "\n\n==== send money ====\n\n";
    
    cout << "balance: " << d.AmountOfMoney << "$" << endl;
    
    string nameToTransfer;
    int moneyToGive;
    
    cout << "\nto whom you want to sent the money: " << endl;
    cin >> nameToTransfer;
    
    cout << "\nhow much money you want to give: " << endl;
    cin >> moneyToGive;
    
    if (moneyToGive > d.AmountOfMoney || moneyToGive < 0) {
        cout << "\ninsufficent funds! sending money cancelled" << endl;
    }else {
        d.AmountOfMoney -= moneyToGive;
        cout << '\n' << moneyToGive << "$ sended to " << nameToTransfer << ". balance: " << d.AmountOfMoney << "$" << endl;
    }
}

int main() {
    variable amount;
    amount.AmountOfMoney = 0;
    while (true) {
        cout << "\n\n====simple banking system====\n\n";
        
        cout << "1.deposit" << endl;
        cout << "2.withdraw" << endl;
        cout << "3.send money!" << endl;
        cout << "4.exit" << endl;
        
        int choice;
        
        cout << "write your choice: " << endl;
        cin >> choice;
        
        switch(choice) {
            case 1:
                deposit(amount);
                break;
            
            case 2:
                withdraw(amount);
                break;
            
            case 3:
                sendMoney(amount);
                break;
            
            case 4:
                cout << "\nthanks for using our program!!!😄" << endl;
                return 0;
            
            default:
                cout << "\nInvalid choice. Please enter 1-4.\n";
        }
        
    }
    return 0;
}
