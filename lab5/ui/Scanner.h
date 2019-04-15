//
// Created by dani on 3/27/19.
//

#ifndef LAB5_SCANNER_H
#define LAB5_SCANNER_H

#include <vector>
#include <string>
#include "../service/VictimFileService.h"
#include "../model/Mode.h"

class Scanner {
private:
    VictimFileService victimFileService;
    Mode currentMode;
   // DynamicVector<VictimFile>::Iterator victimFileIterator;
   int currentIterationIndex;
    vector<VictimFile> transferList;
    void listModeA();

    void addModeA(vector<string> inputAsTokens);

    void removeModeA(string victimName);

    void setMode(vector<string> inputAsTokens);

    void updateModeA(string victimName, vector<string> inputAsTokens);
    void print(vector<string> inputAsTokens);
    void print(vector<VictimFile> victimFilesToPrint);
    VictimFile victimFileFromTokens(vector<string> tokens);
    bool isValidNaturalNumber(string input);
    bool is_number(string s);
    void listModeB(vector<string> inputAsTokens);
    void nextModeB();
    void saveModeB(string name);
    void mylistModeB();
public:
    /**
     * Run console until exit command given, through a brand new service.
     */
    void runConsole();

    Scanner(const VictimFileService &victimFileService);

    void setIterationStart();
};


#endif //LAB5_SCANNER_H
