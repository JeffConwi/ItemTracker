#include "ItemTracker.h"
#include <iostream>
using namespace std;
int main() {
    ItemTracker tracker;
    int choice;
    string inputItem;

    while (true) {
        cout << "Menu\n";
        cout << "1. Search for an item\n";
        cout << "2. Print frequencies of all items\n";
        cout << "3. Print histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item to search for: ";
                cin >> inputItem;
                cout << inputItem << " appears " << tracker.searchItem(inputItem) << " times.\n";
                break;
            case 2:
                tracker.printFrequencies();
                break;
            case 3:
                tracker.printHistogram();
                break;
            case 4:
                tracker.exitProgram();
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
