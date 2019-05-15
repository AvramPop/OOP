
#include "Scanner.h"
#include "FileSaver.h"
#include <iostream>
#include <regex>
#include <stdlib.h>
#include <QDebug>

using namespace std;
void Scanner::runConsole(){
    bool inputNotExit = true;
    string command;
    while(inputNotExit){
        cin >> command;
        if(command == "exit"){
            inputNotExit = false;
        } else if(command == "list"){
            if(currentMode.getMode() == "A"){
                listModeA();
            } else if(currentMode.getMode() == "B"){
                listModeB();
            }
        } else if(command == "add"){
            if(currentMode.getMode() == "A"){
                addModeA();
            }
        } else if(command == "fileLocation"){
            string path;
            getline(std::cin, path);
            path = removeUnnecessaryWhitespaces(path);
            unique_ptr<FileRepository<VictimFile>> repository = make_unique<FileRepository<VictimFile>>(path);
            unique_ptr<VictimFileService> temporaryService = make_unique<VictimFileService>(move(repository));
            victimFileService = move(temporaryService);
        } else if(command == "update"){
            if(currentMode.getMode() == "A"){
                updateModeA();
            }
        } else if(command == "mylistLocation"){
            string path;
            getline(std::cin, path);
            path = removeUnnecessaryWhitespaces(path);
            myListLocation = path;
        } else if(command == "mode"){
            setMode();
            if(currentMode.getMode() == "B"){
                setIterationStart();
            }
        } else if(command == "delete"){
            if(currentMode.getMode() == "A"){
                removeModeA();
            }
        } else if(command == "next"){
            if(currentMode.getMode() == "B"){
                nextModeB();
            }
        } else if(command == "save"){
            if(currentMode.getMode() == "B"){
                saveModeB();
            }
        } else if(command == "mylist"){
            if(currentMode.getMode() == "B"){
                mylistModeB();
            }
        }
    }
}

void Scanner::listModeA(){
    print(victimFileService->getList());
}

void Scanner::addModeA(){
    VictimFile victimFileFromInput;
    try{
        cin.ignore();
        cin >> victimFileFromInput;
    } catch(exception& exception){
        return;
    }
    victimFileService->addVictimFile(victimFileFromInput);
}

void Scanner::removeModeA(){
    string victimName;
    getline(std::cin, victimName);
    victimName = removeUnnecessaryWhitespaces(victimName);
    victimFileService->removeVictimFile(victimName);
}

void Scanner::setMode(){
    string mode;
    getline(std::cin, mode);
    mode = removeUnnecessaryWhitespaces(mode);
    if(mode == "A" || mode == "B"){
        currentMode.setMode(mode);
    }
}

void Scanner::updateModeA(){ // todo something can break here and throw logic error
    VictimFile victimFileFromInput;
    try{
        cin.ignore();
        cin >> victimFileFromInput;
    } catch(exception& exception){
        return;
    }
    victimFileService->updateVictimFile(victimFileFromInput.getName(), victimFileFromInput);

}

void Scanner::print(vector<VictimFile> victimFilesToPrint){
    for(auto& victimFileToPrint : victimFilesToPrint){

        cout << victimFileToPrint << endl;
    }
}

bool Scanner::isValidNaturalNumber(string input){
    return isNumber(input) && atoi(input.data()) >= 0;
}

bool Scanner::isNumber(string stringToTest){
    return !stringToTest.empty() && all_of(stringToTest.begin(), stringToTest.end(), ::isdigit);
}

Scanner::Scanner(unique_ptr<VictimFileService> victimFileService){
    myListLocation = "/temp/oop";
    this->victimFileService = move(victimFileService);
}

void Scanner::listModeB(){
    string input;
    getline(std::cin, input);
    input = removeUnnecessaryWhitespaces(input);
    stringstream inputAsStringStream(input);
    string token;
    vector<string> inputAsTokens;
    while(getline(inputAsStringStream, token, ',')){ // converts to vector of tokens
        token = std::regex_replace(token, std::regex("^ +"), "");
        inputAsTokens.push_back(token);
    }
    if(inputAsTokens.size() == 2){
        if(isValidNaturalNumber(inputAsTokens[1])){
            int conversion = atoi(inputAsTokens[1].data());
            print(victimFileService->getVectorOfFilesWithOriginAndLowerAge(inputAsTokens[0], conversion));
        }
    } else if(inputAsTokens.empty()) {
        listModeA();
    }
}

void Scanner::nextModeB(){
    if(currentIterationIndex == victimFileService->getList().size()){
        setIterationStart();
        cout << victimFileService->getList()[currentIterationIndex] << endl;
    } else {
        cout << victimFileService->getList()[currentIterationIndex] << endl;
    }
    currentIterationIndex++;
}

void Scanner::saveModeB(){
    string name;
    getline(std::cin, name);
    name = removeUnnecessaryWhitespaces(name);
    VictimFile victimFileToTransfer = victimFileService->getVictimFileWithName(name);
    if(!(find(transferList.begin(), transferList.end(), VictimFile(name)) != transferList.end())){
        transferList.push_back(victimFileToTransfer);
    }
    saveMyListToFile();
}

void Scanner::mylistModeB(){
    string extension = getPathExtension();
    string command;
    if(extension == "txt"){
        command += "gedit ";
        command += myListLocation;
    } else if(extension == "html"){
        command += "timeout 15 chromium-browser ";
        command += myListLocation;
    } else if(extension == "csv"){
        command += "gedit ";
        command += myListLocation;
    }
    system(command.data());
}

void Scanner::setIterationStart(){
    currentIterationIndex = 0;
}

string Scanner::removeUnnecessaryWhitespaces(string stringToUpdate){
    return std::regex_replace(stringToUpdate, std::regex("^ +| +$|( ) +"), "$1");
}

void Scanner::saveMyListToFile(){
    unique_ptr<FormattedFileSaver<VictimFile>> fileSaver;
    string extension = getPathExtension();
    if(extension == "txt"){
        fileSaver = make_unique<TXTSaver<VictimFile>>(myListLocation);
    } else if(extension == "html"){
        fileSaver = make_unique<HTMLSaver<VictimFile>>(myListLocation);
    } else if(extension == "csv"){
        fileSaver = make_unique<CSVSaver<VictimFile>>(myListLocation);
    }
    fileSaver->save(transferList);
}

string Scanner::getPathExtension(){
    return myListLocation.substr(myListLocation.find_last_of(".") + 1);
}
