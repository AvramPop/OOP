//
// Created by dani on 3/27/19.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include "Scanner.h"
using namespace std;
void Scanner::runConsole(){
    char userInput[1000];
    string inputAsString;
    string command;
    bool inputNotExit = true;
    bool isFirstToken;
    while(inputNotExit){
        scanf(" %[^\n]s", userInput);
        vector<string> inputAsTokens;
        inputAsString = userInput;
        string delimiter = " ";
        command = inputAsString.substr(0, inputAsString.find(delimiter));
        auto indexAfterCommand = inputAsString.find(" ") + 1;
        inputAsString = inputAsString.substr(indexAfterCommand);
        stringstream inputAsStringStream(inputAsString);
        string token;
        string nameToken;
        isFirstToken = true;
        while(getline(inputAsStringStream, token, ',')){
            token = std::regex_replace(token, std::regex("^ +"), "");
            if(isFirstToken){
                isFirstToken = false;
                nameToken = token;
            }
            inputAsTokens.push_back(token);
        }
        if(command == "exit"){
            inputNotExit = false;
        } else if(command == "list"){
            if(currentMode.getMode() == "A"){
                listModeA();
            } else if(currentMode.getMode() == "B"){
                listModeB(inputAsTokens);
            }
        } else if(command == "add"){
            if(currentMode.getMode() == "A"){
                addModeA(inputAsTokens);
            }
        } else if(command == "update"){
            if(currentMode.getMode() == "A"){
                updateModeA(nameToken, inputAsTokens);
            }
        } else if(command == "mode"){
            setMode(inputAsTokens);
            if(currentMode.getMode() == "B"){
                setIterationStart();
            }
        } else if(command == "delete"){
            if(currentMode.getMode() == "A"){
                removeModeA(nameToken);
            }
        } else if(command == "next"){
            if(currentMode.getMode() == "B"){
                nextModeB();
            }
        } else if(command == "save"){
            if(currentMode.getMode() == "B"){
                saveModeB(nameToken);
            }
        } else if(command == "mylist"){
            if(currentMode.getMode() == "B"){
                mylistModeB();
            }
        }
    }
}

void Scanner::listModeA(){
    print(victimFileService.getList());
}

void Scanner::addModeA(vector<string> inputAsTokens){
    if(isValidNaturalNumber(inputAsTokens[2])){
        VictimFile victimFileFromInput = victimFileFromTokens(inputAsTokens);
        victimFileService.addVictimFile(victimFileFromInput);
    }
}

void Scanner::removeModeA(string victimName){
    victimFileService.removeVictimFile(victimName);
}

void Scanner::setMode(vector<string> inputAsTokens){
    if(inputAsTokens[0] == "A" || inputAsTokens[0] == "B"){
        currentMode.setMode(inputAsTokens[0]);
    }
}

void Scanner::updateModeA(string victimName, vector<string> inputAsTokens){ // todo something can break here and throw logic error
    if(isValidNaturalNumber(inputAsTokens[2])){
        VictimFile victimFileFromInput = victimFileFromTokens(inputAsTokens);
        victimFileService.updateVictimFile(victimName, victimFileFromInput);
    }
}

void Scanner::print(vector<string> inputAsTokens){
    for(const auto &inputAsToken : inputAsTokens){
        cout << inputAsToken << " ";
    }
    cout << endl;
}

void Scanner::print(DynamicVector<VictimFile> victimFilesToPrint){
    for(int i = 0; i < victimFilesToPrint.getSize(); i++){
        cout << victimFilesToPrint[i].toPlainString() << endl;
    }
}

VictimFile Scanner::victimFileFromTokens(vector<string> tokens){
    return VictimFile(tokens[0], tokens[1], atoi(tokens[2].data()), tokens[3]);
}

//bool Scanner::isValidInput(vector<string> input){
//    char* endPointer = NULL; //todo this one is for strtol
//    strtol(input[2].data(), &endPointer, 10);
//    return  *endPointer == '\0' && atoi(input[2].data()) >= 0;
//}

bool Scanner::isValidNaturalNumber(string input){
//    char** endPointer = NULL; //todo this one is for strtol
//    strtol(input[2].data(), endPointer, 10);
    return is_number(input) && atoi(input.data()) >= 0;
}

bool Scanner::is_number(string s){
    auto it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

Scanner::Scanner(const VictimFileService &victimFileService) : victimFileService(victimFileService){}

void Scanner::listModeB(vector<string> inputAsTokens){
    if(inputAsTokens.size() == 2){
        if(isValidNaturalNumber(inputAsTokens[1])){
            print(victimFileService.getVectorOfFilesWithOriginAndLowerAge(inputAsTokens[0], atoi(inputAsTokens[1].data())));
        }
    } else {
        listModeA();
    }
}

void Scanner::nextModeB(){
    currentIterationIndex++;
    if(currentIterationIndex == victimFileService.getList().getSize()){
        setIterationStart();
    } else {
        cout << victimFileService.getList()[currentIterationIndex].toPlainString() << endl;
    }
}

void Scanner::saveModeB(string name){
    VictimFile victimFileToTransfer = victimFileService.getVictimFileWithName(name);
    if(!transferList.containsElement(VictimFile(name))){
        transferList.add(victimFileToTransfer);
    }
}

void Scanner::mylistModeB(){
    for(int i = 0; i < transferList.getSize(); i++){
        cout << transferList[i].toPlainString() << endl;
    }
}

void Scanner::setIterationStart(){
    currentIterationIndex = 0;
    cout << victimFileService.getList()[currentIterationIndex].toPlainString() << endl;
}
