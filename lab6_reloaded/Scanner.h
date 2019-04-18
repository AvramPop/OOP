//
// Created by dani on 4/17/19.
//

#ifndef LAB6_RELOADED_SCANNER_H
#define LAB6_RELOADED_SCANNER_H


#include "VictimFileService.h"
#include "Mode.h"

class Scanner {
private:
    VictimFileService victimFileService;
    Mode currentMode;
    int currentIterationIndex;
    vector<VictimFile> transferList;
    void listModeA();
    void addModeA();
    void removeModeA();
    void setMode();
    void updateModeA();
    void print(vector<VictimFile> victimFilesToPrint);
    bool isValidNaturalNumber(string input);
    bool isNumber(string s);
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

    Scanner(const VictimFileService &victimFileService);
    Scanner(){};

    void setIterationStart();
};


#endif //LAB6_RELOADED_SCANNER_H
