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

template <typename TemplateClass>
class FileRepository {
private:
    const std::string pathToRepository;
    void loadBufferFromFile();
    void dumpBufferToFile();
    bool isEmpty(ifstream& file);
    vector<TemplateClass> buffer;
    int indexOfElement(TemplateClass element);
public:
    FileRepository<TemplateClass>(std::string path) : pathToRepository(path){}

    void add(TemplateClass &element);

    std::vector<TemplateClass> getList();

    bool containsElement(TemplateClass element);

    void remove(TemplateClass element);

    void update(TemplateClass element);

    int getSize();

    TemplateClass& at(int index);
};

template<typename TemplateClass>
void FileRepository<TemplateClass>::add(TemplateClass &element){
    loadBufferFromFile();
    buffer.push_back(element);
    dumpBufferToFile();
}

template<typename TemplateClass>
std::vector<TemplateClass> FileRepository<TemplateClass>::getList(){
    loadBufferFromFile();
    vector<TemplateClass> temporaryBuffer(buffer);
    buffer.clear();
    //dumpBufferToFile();
    return temporaryBuffer;
}

template<typename TemplateClass>
bool FileRepository<TemplateClass>::containsElement(TemplateClass element){
    loadBufferFromFile();
    bool contains = find(buffer.begin(), buffer.end(), element) != buffer.end();
    buffer.clear();
    //dumpBufferToFile();
    return contains;
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::remove(TemplateClass element){
    loadBufferFromFile();
    if(containsElement(element)){
        buffer.erase(std::remove(buffer.begin(), buffer.end(), element), buffer.end());
    }
    dumpBufferToFile();
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::update(TemplateClass element){
    loadBufferFromFile();
    if(containsElement(element)){
        buffer[indexOfElement(element)] = element;
    }
    dumpBufferToFile();
}

template<typename TemplateClass>
int FileRepository<TemplateClass>::getSize(){
    loadBufferFromFile();
    int size = buffer.size();
    buffer.clear();
    //dumpBufferToFile();
    return size;
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::loadBufferFromFile(){
    std::ifstream fin(pathToRepository);
    if(isEmpty(fin)){
        buffer.clear();
    } else {
        VictimFile temporaryVictimFile;
        buffer.clear();
        while(fin >> temporaryVictimFile){
            buffer.push_back(temporaryVictimFile);
        }
    }
    fin.close();
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::dumpBufferToFile(){
    ofstream fout(pathToRepository);
    for(int i = 0; i < buffer.size() - 1; i++){
        fout << buffer.at(i).toFormattedString() << endl;
    }
    if(buffer.size() > 0){
        fout << buffer.at(buffer.size() - 1).toFormattedString();
    }
    fout.close();
    buffer.clear();
}

template<typename TemplateClass>
TemplateClass& FileRepository<TemplateClass>::at(int index){
    loadBufferFromFile();
    if(index < getSize()){
        TemplateClass element = buffer[index];
        buffer.clear();
        return element;
    } else {
        buffer.clear();
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
    for(int i = 0; i < buffer.size(); i++){
        if(buffer[i] == element){
            indexOfElementToRemove = i;
        }
    }
    return indexOfElementToRemove;
}



#endif //LAB5_FILEREPOSITORY_H
