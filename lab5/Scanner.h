//
// Created by dani on 3/27/19.
//

#ifndef LAB5_SCANNER_H
#define LAB5_SCANNER_H

#include <vector>
#include <string>
#include "VictimFileService.h"
#include "Mode.h"

class Scanner {
private:
    VictimFileService victimFileService;
    Mode currentMode;
    void list();

    void add(vector<string> inputAsTokens);

    void remove(string inputAsString);

    void setMode(vector<string> inputAsTokens);

    void update(string victimName, vector<string> inputAsTokens);
    void print(vector<string> inputAsTokens);
    void print(DynamicVector<VictimFile> victimFilesToPrint);
    VictimFile victimFileFromTokens(vector<string> tokens);
    bool isValidInput(vector<string> input);
    bool isNumber(string potentialNumber);
public:

    void runConsole();
};


#endif //LAB5_SCANNER_H
