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
    void listModeA();

    void addModeA(vector<string> inputAsTokens);

    void removeModeA(string victimName);

    void setMode(vector<string> inputAsTokens);

    void updateModeA(string victimName, vector<string> inputAsTokens);
    void print(vector<string> inputAsTokens);
    void print(DynamicVector<VictimFile> victimFilesToPrint);
    VictimFile victimFileFromTokens(vector<string> tokens);
    bool isValidInput(vector<string> input);
    bool is_number(string s);
public:
    /**
     * Run console until exit command given, through a brand new service.
     */
    void runConsole();

    Scanner(const VictimFileService &victimFileService);

    void listModeB();

    void nextModeB();

    void saveModeB();

    void mylistModeB();
};


#endif //LAB5_SCANNER_H
