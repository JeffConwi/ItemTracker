#ifndef CORNERGROCER_SRC_ITEM_TRACKER_H
#define CORNERGROCER_SRC_ITEM_TRACKER_H


#include <map>
#include <string>

using namespace std;

class ItemTracker {
private:
    map<string, int> itemFrequencies;  // Map to store item frequencies
    const string inputFile;             // Name of the input file
    const string backupFile;            // Name of the backup file

    void readInputFile();               // Reads input file and populates map
    void writeBackupFile();             // Writes frequencies to backup file

public:
    ItemTracker();                      // Constructor
    int searchItem(const string& item); // Searches for an item and returns its frequency
    void printFrequencies();            // Prints frequencies of all items
    void printHistogram();              // Prints histogram of item frequencies
    void exitProgram();                 // Handles program exit
};

#endif // CORNERGROCER_SRC_ITEM_TRACKER_H
