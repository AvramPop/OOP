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
    /**
     * Get index of element in repository.
     */
    int indexOfElement(TemplateClass element);
    const std::string pathToRepository;
    /**
     * Load Buffer from file.
     */
    void loadBufferFromFile();
    /**
     * Dump in-memory buffer to file.
     */
    void dumpBufferToFile();
    /**
     * Check if file is empty.
     */
    bool fileIsEmpty(std::ifstream &file);
    std::vector<TemplateClass> buffer;
    /**
     * Check whether in memory buffer contains element.
     * @param element
     * @return
     */
    bool liveContainsElement(TemplateClass element);
public:
    FileRepository<TemplateClass>(std::string path) : pathToRepository(path){
        buffer = std::vector<TemplateClass>();
    }
    /**
     * Add generic element to file repository
     */
    void add(TemplateClass element);
    /**
     * Get buffer as vector of elements.
     * @return
     */
    std::vector<TemplateClass> asList();
    /**
     * Check whether repository contains given element.
     */
    bool containsElement(TemplateClass element);
    /**
     * Remove generic element from file repository
     * @param element
     */
    void remove(TemplateClass element);
    /**
     * Update generic element in file repository
     */
    void update(TemplateClass element);
    /**
     * Get size of repository.
     */
    int getSize();
    /**
     * Get mutable element at index in repository.
     */
    TemplateClass& at(int index);
    TemplateClass operator[](int index);
    FileRepository& operator=(const FileRepository& fileRepository);

    FileRepository();

};

template<typename TemplateClass>
FileRepository<TemplateClass>& FileRepository<TemplateClass>::operator=(const FileRepository& fileRepository){
    if(this == &fileRepository){
        return *this;
    }
    buffer = fileRepository.buffer;
    const_cast<std::string&>(pathToRepository) = fileRepository.pathToRepository;
    return *this;
}

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
    std::ofstream fout(pathToRepository);
    fout << "";
    if(buffer.size() > 0){
        for(int i = 0; i < buffer.size() - 1; i++){
            fout << buffer[i].toFormattedString() << std::endl;
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
        throw std::exception();
    }
}

template<typename TemplateClass>
int FileRepository<TemplateClass>::getSize(){
    loadBufferFromFile();
    int size = buffer.size();
    buffer.clear();
    return size;
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::update(TemplateClass element){
    loadBufferFromFile();
    if(liveContainsElement(element)){
        buffer[indexOfElement(element)] = element;
    }
    dumpBufferToFile();
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

template<typename TemplateClass>
bool FileRepository<TemplateClass>::containsElement(TemplateClass element){
    loadBufferFromFile();
    bool contains = find(buffer.begin(), buffer.end(), element) != buffer.end();
    buffer.clear();
    return contains;
}

template<typename TemplateClass>
bool FileRepository<TemplateClass>::liveContainsElement(TemplateClass element){
    return find(buffer.begin(), buffer.end(), element) != buffer.end();
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::remove(TemplateClass element){
    loadBufferFromFile();
    if(liveContainsElement(element)){
        buffer.erase(std::remove(buffer.begin(), buffer.end(), element), buffer.end());
    }
    dumpBufferToFile();
}

template<typename TemplateClass>
TemplateClass FileRepository<TemplateClass>::operator[](int index){
    loadBufferFromFile();
    if(index < buffer.size()){
        TemplateClass element = buffer[index];
        buffer.clear();
        return element;
    } else {
        buffer.clear();
        throw std::exception();
    }
}

template<typename TemplateClass>
FileRepository<TemplateClass>::FileRepository(){}


#endif //LAB6_RELOADED_FILEREPOSITORY_H
