//
// Created by dani on 4/26/19.
//

#ifndef LAB6_RELOADED_FILESAVER_H
#define LAB6_RELOADED_FILESAVER_H

#include <string>
#include <vector>
#include <fstream>
#include "VictimFile.h"

template <typename TemplateClass>
class FormattedFileSaver {
    std::string path;
public:
    std::string getPath() { return path; }
    virtual ~FormattedFileSaver() {};
    FormattedFileSaver(std::string path) : path(path) {};
    virtual void save(std::vector<TemplateClass> list) = 0;
};

template <typename TemplateClass>
class HTMLSaver : public FormattedFileSaver<TemplateClass> {
public:
    virtual void save(std::vector<TemplateClass> list) override{
        std::ofstream fout(this->getPath());
        if(list.size() > 0){
            string outputHTML;
            outputHTML += topHTML();
            for(int i = 0; i < list.size(); i++){
                outputHTML += formattedVictimFile(list[i]);
            }
            outputHTML += bottomHTML();
            fout << outputHTML;
            fout.close();
        }
    }

private:
    string topHTML() {
        string result = "<!DOCTYPE html><html><head><title>Transfer list</title></head><body><table border=\"1\"><tr><td>Victim Name</td><td>Place of origin</td><td>Age</td><td>Photograph</td></tr>";
        return result;
    }

    string bottomHTML() {
        string result = "</table></body></html>";
        return result;
    }

    string formattedVictimFile(VictimFile victimFile){
        string result = "<tr><td>";
        result +=victimFile.getName();
        result += "</td><td>";
        result += victimFile.getPlaceOfOrigin();
        result += "</td><td>";
        result += to_string(victimFile.getAge());
        result += "</td><td>";
        result += victimFile.getPhotograph();
        result += "</td></tr>";
        return result;
    };

public:
    HTMLSaver(std::string path) : FormattedFileSaver<TemplateClass>(path){};
};

template <typename TemplateClass>
class CSVSaver : public FormattedFileSaver<TemplateClass> {
public:
    virtual void save(std::vector<TemplateClass> list) override {
        std::ofstream fout(this->getPath());
        fout << "";
        if(list.size() > 0){
            for(int i = 0; i < list.size(); i++){
                VictimFile currentVictimFile = list[i];
                fout << currentVictimFile.getName() << "," << currentVictimFile.getPlaceOfOrigin() << ","
                     << currentVictimFile.getAge() << "," << currentVictimFile.getPhotograph() << "\n";
            }
        }
        fout.close();
    }
    CSVSaver(std::string path) : FormattedFileSaver<TemplateClass>(path){};
};

template <typename TemplateClass>
class TXTSaver : public FormattedFileSaver<TemplateClass> {
public:
    virtual void save(std::vector<TemplateClass> list) override {
        std::ofstream fout(this->getPath());
        fout << "";
        if(list.size() > 0){
            for(int i = 0; i < list.size(); i++){
                fout << list[i].toFormattedString() << std::endl;
            }
        }
        fout.close();
    }
    TXTSaver(std::string path) : FormattedFileSaver<TemplateClass>(path){};
};

#endif //LAB6_RELOADED_FILESAVER_H
