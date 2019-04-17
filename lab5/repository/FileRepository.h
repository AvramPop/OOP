//
// Created by dani on 4/16/19.
//

#ifndef LAB5_FILEREPOSITORY_H
#define LAB5_FILEREPOSITORY_H

#include "Repository.h"
#include "../model/VictimFile.h"
#include <string>
#include <iostream>
#include <fstream>

template <typename TemplateClass>
class FileRepository : public virtual Repository<TemplateClass> {
private:
    const std::string pathToRepository;
    void loadBufferFromFile();
    void dumpBufferToFile();
    bool isEmpty(ifstream& file);
public:
    FileRepository<TemplateClass>(std::string path) : pathToRepository(path){}

    void add(TemplateClass &element) override;

    std::vector<TemplateClass> getList() override;

    bool containsElement(TemplateClass element) override;

    void remove(TemplateClass element) override;

    void update(TemplateClass element) override;

    int getSize() override;

    TemplateClass &operator[](int index) override;

    TemplateClass& at(int index) override;
};

template<typename TemplateClass>
void FileRepository<TemplateClass>::add(TemplateClass &element){
    loadBufferFromFile();
    Repository<TemplateClass>::add(element);
    dumpBufferToFile();
}

template<typename TemplateClass>
std::vector<TemplateClass> FileRepository<TemplateClass>::getList(){
    loadBufferFromFile();
    vector<TemplateClass> temporaryBuffer = Repository<TemplateClass>::getList();
    dumpBufferToFile();
    return temporaryBuffer;
}

template<typename TemplateClass>
bool FileRepository<TemplateClass>::containsElement(TemplateClass element){
    loadBufferFromFile();
    bool contains = Repository<TemplateClass>::containsElement(element);
    dumpBufferToFile();
    return contains;
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::remove(TemplateClass element){
    loadBufferFromFile();
    Repository<TemplateClass>::remove(element);
    dumpBufferToFile();
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::update(TemplateClass element){
    loadBufferFromFile();
    Repository<TemplateClass>::update(element);
    dumpBufferToFile();
}

template<typename TemplateClass>
int FileRepository<TemplateClass>::getSize(){
    loadBufferFromFile();
    int size = Repository<TemplateClass>::getSize();
    dumpBufferToFile();
    return size;
}

template<typename TemplateClass>
TemplateClass &FileRepository<TemplateClass>::operator[](int index){
    loadBufferFromFile();
    if(index < getSize()){
        TemplateClass element = Repository<TemplateClass>::buffer[index];
        dumpBufferToFile();
        return element;
    } else {
        dumpBufferToFile();
        throw exception();
    }
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::loadBufferFromFile(){
    std::ifstream fin(pathToRepository);
    if(isEmpty(fin)){
        Repository<TemplateClass>::buffer.clear();
    } else {
        VictimFile temporaryVictimFile;
        Repository<TemplateClass>::buffer.clear();
        while(fin >> temporaryVictimFile){
            Repository<TemplateClass>::buffer.push_back(temporaryVictimFile);
        }
    }
    fin.close();
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::dumpBufferToFile(){
    ofstream fout(pathToRepository);
    for(VictimFile victimFile : Repository<TemplateClass>::buffer){
        fout << victimFile.toFormattedString();
    }
    fout.close();
    Repository<TemplateClass>::buffer.clear();
}

template<typename TemplateClass>
TemplateClass& FileRepository<TemplateClass>::at(int index){
    loadBufferFromFile();
    if(index < getSize()){
        TemplateClass element = Repository<TemplateClass>::buffer[index];
        dumpBufferToFile();
        return element;
    } else {
        dumpBufferToFile();
        throw exception();
    }
}

template<typename TemplateClass>
bool FileRepository<TemplateClass>::isEmpty(ifstream& file){
    return file.peek() == std::ifstream::traits_type::eof();
}

#endif //LAB5_FILEREPOSITORY_H
