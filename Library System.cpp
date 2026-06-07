#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
};
int main() {

    Book library[100];
    int bookCount = 0;

    library[0]={1001, "Data Structures", "Mark Allen"};
    library[1]={1002, "Clean Code", "Robert Martin"};
    bookCount = 2;

    int choice = 0;

    while (choice != 4) {
        cout<<"\n=== SIMPLE LIBRARY ===\n";
        cout<<"1. Add Book\n2. Search by ID\n3. Display All\n4. Exit\nChoice: ";
        cin>>choice;

        if (choice == 1) {
            if (bookCount >= 100) {
                cout << "Error: Library capacity reached!\n";
            } else {
                Book b;
                cout<<"Enter ID: "; cin >> b.id; cin.ignore();
                cout<<"Enter Title: "; getline(cin, b.title);
                cout<<"Enter Author: "; getline(cin, b.author);

                library[bookCount] = b;
                bookCount++;
                cout<<"Book added!\n";
            }
        }
        else if (choice == 2) {
            int id;
            cout<<"Enter ID to search: ";
            cin>>id;

            int found = 0;

            for (int i = 0; i < bookCount; i++) {
                if (library[i].id == id) {
                    cout<<"Found: "<<library[i].title<<" by "<<library[i].author<<"\n";
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                cout<<"Book not found.\n";
            }
        }
        else if (choice == 3) {
            cout<<"\n--- Inventory ---\n";
            for (int i = 0; i < bookCount; i++) {
                cout<<"ID: "<<library[i].id<<" | " <<library[i].title<<" by "<<library[i].author<<"\n";
            }
        }
    }
    return 0;
}
