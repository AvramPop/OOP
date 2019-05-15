//
// Created by dani on 4/16/19.
//

#ifndef LAB5_FILEREPOSITORY_H
#define LAB5_FILEREPOSITORY_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Repository.h"

template <typename TemplateClass>
class FileRepository : public Repository<TemplateClass> {
private:
    const std::string pathToRepository;
    void loadBufferFromFile();
    void dumpBufferToFile();
    bool isEmpty(ifstream& file);
    //vector<TemplateClass> buffer;
    int indexOfElement(TemplateClass element) override;
public:
    FileRepository<TemplateClass>(std::string path) : pathToRepository(path){}

    void add(TemplateClass &element) override;

    std::vector<TemplateClass> getList() override;

    bool containsElement(TemplateClass element) override;

    void remove(TemplateClass element) override;

    void update(TemplateClass element) override;

    int getSize() override;

    TemplateClass& at(int index) override;
};

template<typename TemplateClass>
void FileRepository<TemplateClass>::add(TemplateClass &element){
    loadBufferFromFile();
    this->buffer.push_back(element);
    dumpBufferToFile();
}

template<typename TemplateClass>
std::vector<TemplateClass> FileRepository<TemplateClass>::getList(){
    loadBufferFromFile();
    vector<TemplateClass> temporaryBuffer(this->buffer);
    this->buffer.clear();
    //dumpBufferToFile();
    return temporaryBuffer;
}

template<typename TemplateClass>
bool FileRepository<TemplateClass>::containsElement(TemplateClass element){
    loadBufferFromFile();
    bool contains = find(this->buffer.begin(), this->buffer.end(), element) != this->buffer.end();
    this->buffer.clear();
    //dumpBufferToFile();
    return contains;
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::remove(TemplateClass element){
    loadBufferFromFile();
    if(containsElement(element)){
        this->buffer.erase(std::remove(this->buffer.begin(), this->buffer.end(), element), this->buffer.end());
    }
    dumpBufferToFile();
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::update(TemplateClass element){
    loadBufferFromFile();
    if(containsElement(element)){
        this->buffer[indexOfElement(element)] = element;
    }
    dumpBufferToFile();
}

template<typename TemplateClass>
int FileRepository<TemplateClass>::getSize(){
    loadBufferFromFile();
    int size = this->buffer.size();
    this->buffer.clear();
    //dumpBufferToFile();
    return size;
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::loadBufferFromFile(){
    std::ifstream fin(pathToRepository);
    if(isEmpty(fin)){
        this->buffer.clear();
    } else {
        VictimFile temporaryVictimFile;
        this->buffer.clear();
        while(fin >> temporaryVictimFile){
            this->buffer.push_back(temporaryVictimFile);
        }
    }
    fin.close();
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::dumpBufferToFile(){
    ofstream fout(pathToRepository);
    for(int i = 0; i < this->buffer.size() - 1; i++){
        fout << this->buffer.at(i).toFormattedString() << endl;
    }
    if(this->buffer.size() > 0){
        fout << this->buffer.at(this->buffer.size() - 1).toFormattedString();
    }
    fout.close();
    this->buffer.clear();
}

template<typename TemplateClass>
TemplateClass& FileRepository<TemplateClass>::at(int index){
    loadBufferFromFile();
    if(index < getSize()){
        TemplateClass element = this->buffer[index];
        this->buffer.clear();
        return element;
    } else {
        this->buffer.clear();
        throw exception();
    }
}

template<typename TemplateClass>
bool FileRepository<TemplateClass>::isEmpty(ifstream& file){
    return file.peek() == std::ifstream::traits_type::eof();
}

template <typename TemplateClass>
int FileRepository<TemplateClass>::indexOfElement(TemplateClass element) {
    int indexOfElementToRemove = -1;
    for(int i = 0; i < this->buffer.size(); i++){
        if(this->buffer[i] == element){
            indexOfElementToRemove = i;
        }
    }
    return indexOfElementToRemove;
}



#endif //LAB5_FILEREPOSITORY_H
