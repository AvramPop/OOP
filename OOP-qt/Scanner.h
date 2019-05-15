#ifndef SCANNER_H
#define SCANNER_H

#include "VictimFileService.h"
#include "Mode.h"

class Scanner {
private:
    unique_ptr<VictimFileService> victimFileService;
    Mode currentMode;
    int currentIterationIndex;
    string myListLocation;
    vector<VictimFile> transferList;
    void listModeA();
    void addModeA();
    void removeModeA();
    void setMode();
    void updateModeA();
    void print(vector<VictimFile> victimFilesToPrint);
    bool isValidNaturalNumber(string input);
    bool isNumber(string stringToTest);
    void listModeB();
    void nextModeB();
    void saveModeB();
    void mylistModeB();
    string removeUnnecessaryWhitespaces(string stringToUpdate);
public:
    /**
     * Run console until exit command given, through a brand new service.
     */
    void runConsole();
    Scanner(unique_ptr<VictimFileService> victimFileService);
    Scanner(){
        myListLocation = "/temp/oop";
    };
    void setIterationStart();
    void saveMyListToFile();
    string getPathExtension();
};


#endif // SCANNER_H
