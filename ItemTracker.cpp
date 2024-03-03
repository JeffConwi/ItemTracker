#include "ItemTracker.h"
#include <iostream>
#include <fstream>

using namespace std;  // Using namespace std for convenience

// Constructor: Initializes file names and reads input file
ItemTracker::ItemTracker() : inputFile("CS210_Project_Three_Input_File.txt"), 
                             backupFile("frequency.dat") {
    readInputFile();
}

// Reads input file and populates the item frequencies map
void ItemTracker::readInputFile() {
    ifstream file(inputFile);
    string item;

    if (!file.is_open()) {
        cerr << "Error opening input file!" << endl;
        return;
    }

    while (getline(file, item)) {
        if (!item.empty()) {
            itemFrequencies[item]++;
        }
    }

    file.close();
}

// Writes the item frequencies to the backup file
void ItemTracker::writeBackupFile() {
    ofstream backup(backupFile);
    
    if (!backup.is_open()) {
        cerr << "Error opening backup file!" << endl;
        return;
    }

    for (const auto& pair : itemFrequencies) {
        backup << pair.first << " " << pair.second << endl;
    }

    backup.close();
}

// Searches for an item and returns its frequency
int ItemTracker::searchItem(const string& item) {
    auto it = itemFrequencies.find(item);
    if (it != itemFrequencies.end()) {
        return it->second;
    }
    return 0;  // Return 0 if the item is not found
}

// Prints the frequency of each item
void ItemTracker::printFrequencies() {
    for (const auto& pair : itemFrequencies) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

// Prints a histogram of the item frequencies
void ItemTracker::printHistogram() {
    for (const auto& pair : itemFrequencies) {
        cout << pair.first << ": ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

// Handles program exit and writes data to backup file
void ItemTracker::exitProgram() {
    writeBackupFile();
    cout << "Exiting program and saving data..." << endl;
}
