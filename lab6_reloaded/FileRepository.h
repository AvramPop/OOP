//
// Created by dani on 4/17/19.
//

#ifndef LAB6_RELOADED_FILEREPOSITORY_H
#define LAB6_RELOADED_FILEREPOSITORY_H

#include <vector>
#include <algorithm>
#include <string>
#include <fstream>

template <typename TemplateClass>
class FileRepository {
    friend class Test;
private:
    const std::string pathToRepository;
    void loadBufferFromFile();
    void dumpBufferToFile();
    bool fileIsEmpty(std::ifstream &file);
    std::vector<TemplateClass> buffer;
public:
    FileRepository<TemplateClass>(std::string path) : pathToRepository(path){
        buffer = std::vector<TemplateClass>();
    }
    void add(TemplateClass element);
    std::vector<TemplateClass> asList();
    bool containsElement(TemplateClass element);
    void remove(TemplateClass element);
    void update(TemplateClass element);
    int getSize();
    TemplateClass& at(int index);
};

template<typename TemplateClass>
void FileRepository<TemplateClass>::loadBufferFromFile(){
    std::ifstream fin(pathToRepository);
    if(fileIsEmpty(fin)){
        buffer.clear();
    } else {
        TemplateClass temporary;
        buffer.clear();
        while(!fin.eof()){
            fin >> temporary;
            buffer.push_back(temporary);
        }
    }
    fin.close();
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::dumpBufferToFile(){
    ofstream fout(pathToRepository);
    fout << "";
    if(buffer.size() > 0){
        for(int i = 0; i < buffer.size() - 1; i++){
            fout << buffer[i].toFormattedString() << endl;
        }
        if(buffer.size() > 0){
            fout << buffer[buffer.size() - 1].toFormattedString();
        }
    }
    fout.close();
    buffer.clear();
}

template<typename TemplateClass>
bool FileRepository<TemplateClass>::fileIsEmpty(std::ifstream &file){
    return file.peek() == std::ifstream::traits_type::eof();
}

template<typename TemplateClass>
std::vector<TemplateClass> FileRepository<TemplateClass>::asList(){
    loadBufferFromFile();
    std::vector<TemplateClass> temporaryBuffer(buffer);
    buffer.clear();
    return temporaryBuffer;
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::add(TemplateClass element){
    loadBufferFromFile();
    buffer.push_back(element);
    dumpBufferToFile();
}

template<typename TemplateClass>
TemplateClass& FileRepository<TemplateClass>::at(int index){
    loadBufferFromFile();
    if(index < buffer.size()){
        TemplateClass& element = buffer[index];
        buffer.clear();
        return element;
    } else {
        buffer.clear();
        throw exception();
    }
}

template<typename TemplateClass>
int FileRepository<TemplateClass>::getSize(){
    loadBufferFromFile();
    int size = buffer.size();
    buffer.clear();
    return size;
}


#endif //LAB6_RELOADED_FILEREPOSITORY_H
