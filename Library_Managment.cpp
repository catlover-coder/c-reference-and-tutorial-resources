#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <cstdio>

using namespace std;

struct Book {
    string book_Name;
    string author;
    int bookNo;
    bool is_Available;
};                                                                                                          

void addBook();
void searchBook();
int getNextBookID();
void removeBook();
void issueBook();
void returnBook();

int main() {
    while(true) {
        cout << "\n\n===== Library Management System =====\n\n";
        cout << "1. Add book\n";
        cout << "2. Remove book\n";
        cout << "3. Search book\n";
        cout << "4. Issue book\n";
        cout << "5. Return book\n";
        cout << "6. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 2011) {
            printf("\nDAMN!! you caught the secret!!\nhello i am the mahad's program (:\n\n!");
        }

        switch(choice) {
            case 1:
                addBook();
                break;
            case 2:
                removeBook();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                issueBook();
                break;
            case 5:
                returnBook();
                break;
            case 6:
                cout << "Thanks for using our program (:\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

int getNextBookID() {
    ifstream file("BookInfo.txt");
    if (!file) {
        return 1;
    }
    string name, author;
    int id;
    int maxID = numeric_limits<int>::min();
    while (getline(file, name, ',') &&
           getline(file, author, ',') &&
           (file >> id)) {

        file.ignore();

        if (id > maxID) {
            maxID = id;
        }
    }                                                                                                       
    file.close();                                                                                           
    if (maxID == numeric_limits<int>::min()) {
        return 1;
    }
    return maxID + 1;
}

void addBook() {
    cout << "\n\n===== Adding Book =====\n\n";

    Book newBook;

    cin.ignore();

    cout << "Enter the book name: ";
    getline(cin, newBook.book_Name);

    cout << "Enter the author name: ";
    getline(cin, newBook.author);

    newBook.bookNo = getNextBookID();
    newBook.is_Available = true;

    ofstream outFile("BookInfo.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Could not open BookInfo.txt for writing.\n";
        return;
    }

    outFile << newBook.book_Name << ","
            << newBook.author << ","
            << newBook.bookNo << ","
            << newBook.is_Available << endl;
    outFile.close();

    cout << "Book stored successfully! Book ID: " << newBook.bookNo << "\n";
}

void searchBook() {
    cout << "\n\n===== Searching Book =====\n\n";

    int bookid_From_User;
    cout << "Enter the book ID: ";
    cin >> bookid_From_User;

    ifstream readFile("BookInfo.txt");
    if (!readFile) {
        cout << "No books are stored yet.\n";
        return;
    }

    Book temp;
    bool found = false;

    // FIX: Use >> for integer, not getline
    while (getline(readFile, temp.book_Name, ',') &&
           getline(readFile, temp.author, ',') &&
           (readFile >> temp.bookNo) &&
           (readFile.ignore() && (readFile >> temp.is_Available))) {

        string var = (temp.is_Available) ? "true" : "false";

        if (bookid_From_User == temp.bookNo) {
            cout << "\nBook Found!\n";
            cout << "Name:   " << temp.book_Name << "\n";
            cout << "Author: " << temp.author << "\n";
            cout << "ID:     " << temp.bookNo << "\n";
            cout << "Available: " << var << "\n";                                                                       
            found = true;
            break;
        }
    }

    readFile.close();

    if (!found) {
        cout << "No book with ID " << bookid_From_User << " was found.\n";
    }
}

void removeBook() {
    cout << "\n\n===== Removing Book =====\n\n";

    int book_Id_Delete;
    cout << "Enter the book ID: ";
    cin >> book_Id_Delete;

    ifstream rf("BookInfo.txt");
    ofstream temp("temp.txt");
    ofstream delete_file("trash.txt", ios::app);

    Book bck;

    // FIX: Use correct variable names and read integer properly
    while (getline(rf, bck.book_Name, ',') &&
           getline(rf, bck.author, ',') &&
           (rf >> bck.bookNo)) {

        rf.ignore(); // skip newline after bookNo

        // Also need to read the boolean value after the comma
        // Since the file format is: name,author,id,is_Available
        // After reading id, the next character is a comma, then the bool
        char comma;
        rf >> comma; // read the comma
        rf >> bck.is_Available;
        rf.ignore(); // skip the newline after bool

        if (book_Id_Delete == bck.bookNo) {
            delete_file << bck.book_Name << ","
                        << bck.author << ","
                        << bck.bookNo << endl;
        } else {
            temp << bck.book_Name << ","
                 << bck.author << ","
                 << bck.bookNo << ","
                 << bck.is_Available << endl;
        }
    }

    rf.close();
    temp.close();
    delete_file.close();

    remove("BookInfo.txt");
    rename("temp.txt", "BookInfo.txt");

    cout << "Book is deleted successfully!" << endl;
}

void issueBook() {
    cout << "\n\n===== Issuing Book =====\n\n";

    int BookIdIssue;
    cout << "Enter the book ID: ";
    cin >> BookIdIssue;

    ifstream ir("BookInfo.txt");
    ofstream temp("temf.txt");
    Book ib;

    // FIX: Correctly read string, string, int, then bool
    while (getline(ir, ib.book_Name, ',') && 
           getline(ir, ib.author, ',') && 
           (ir >> ib.bookNo)) {
        
        ir.ignore(); // skip the comma after bookNo
        ir >> ib.is_Available;
        ir.ignore(); // skip the newline at the end of the line

        if (BookIdIssue == ib.bookNo) {
            if (ib.is_Available == true) { // simplified condition
                ib.is_Available = false; // FIX: added 'ib.' prefix
                
                temp << ib.book_Name << ","
                     << ib.author << ","
                     << ib.bookNo << ","
                     << ib.is_Available << endl;
                
                cout << "Book is issued!" << endl;
            } else {
                cout << "Book is already issued!" << endl;
                
                temp << ib.book_Name << ","
                     << ib.author << ","
                     << ib.bookNo << ","
                     << ib.is_Available << endl;
            } // FIX: Properly aligned brackets
        } else {
            temp << ib.book_Name << ","
                 << ib.author << ","
                 << ib.bookNo << ","
                 << ib.is_Available << endl;
        }
    }
    
    ir.close();
    temp.close();

    remove("BookInfo.txt");
    rename("temf.txt", "BookInfo.txt");
}

void returnBook() {
    cout << "\n\n===== Return Book =====\n\n";

    int BookIdReturn;
    cout << "Enter the book ID: ";
    cin >> BookIdReturn;

    ifstream rr("BookInfo.txt");
    ofstream temp("temr.txt");
    Book rb;

    // FIX: Correctly read string, string, int, then bool
    while (getline(rr, rb.book_Name, ',') && 
           getline(rr, rb.author, ',') && 
           (rr >> rb.bookNo)) {
        
        rr.ignore(); // skip the comma after bookNo
        rr >> rb.is_Available;
        rr.ignore(); // skip the newline at the end of the line

        if (BookIdReturn == rb.bookNo) {
            if (rb.is_Available == false) { // simplified condition
                rb.is_Available = true; // FIX: added 'ib.' prefix
                
                temp << rb.book_Name << ","
                     << rb.author << ","
                     << rb.bookNo << ","
                     << rb.is_Available << endl;
                
                cout << "Book is returned!" << endl;
            } else {
                cout << "Book is already returned!" << endl;
                
                temp << rb.book_Name << ","
                     << rb.author << ","
                     << rb.bookNo << ","
                     << rb.is_Available << endl;
            } // FIX: Properly aligned brackets
        } else {
            temp << rb.book_Name << ","
                 << rb.author << ","
                 << rb.bookNo << ","
                 << rb.is_Available << endl;
        }
    }
    
    rr.close();
    temp.close();

    remove("BookInfo.txt");
    rename("temr.txt", "BookInfo.txt");
}