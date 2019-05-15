#ifndef FILEREPOSITORY_H
#define FILEREPOSITORY_H


#include <string>
#include <fstream>
#include <algorithm>
#include "Repository.h"
#include "Exception.h"

template <typename TemplateClass>
class FileRepository : public Repository<TemplateClass> {
    friend class Test;

protected:
    virtual FileRepository<TemplateClass>* cloneImplementation() const override { return new FileRepository(*this);}
private:
    /**
     * Get index of element in repository.
     */
    int indexOfElement(TemplateClass element) override;
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
    /**
     * Check whether in memory buffer contains element.
     * @param element
     * @return
     */
    bool liveContainsElement(TemplateClass element);
public:
    FileRepository<TemplateClass>(std::string path) : pathToRepository(path){
        this->buffer = std::vector<TemplateClass>();
    }
    /**
     * Add generic element to file repository
     */
    void add(TemplateClass element) override;
    /**
     * Get buffer as vector of elements.
     * @return
     */
    std::vector<TemplateClass> asList() override;
    /**
     * Check whether repository contains given element.
     */
    bool containsElement(TemplateClass element) override;
    /**
     * Remove generic element from file repository
     * @param element
     */
    void remove(TemplateClass element) override;
    /**
     * Update generic element in file repository
     */
    void update(TemplateClass element) override;
    /**
     * Get size of repository.
     */
    int getSize() override;
    /**
     * Get mutable element at index in repository.
     */
    TemplateClass& at(int index) override;
    TemplateClass operator[](int index) override;
    FileRepository& operator=(const FileRepository& fileRepository);

    FileRepository();

};

template<typename TemplateClass>
FileRepository<TemplateClass>& FileRepository<TemplateClass>::operator=(const FileRepository& fileRepository){
    if(this == &fileRepository){
        return *this;
    }
    this->buffer = fileRepository.buffer;
    const_cast<std::string&>(pathToRepository) = fileRepository.pathToRepository;
    return *this;
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::loadBufferFromFile(){
    std::ifstream fin(pathToRepository);
    if(fileIsEmpty(fin)){
        this->buffer.clear();
    } else {
        TemplateClass temporary;
        this->buffer.clear();
        while(!fin.eof()){
            try{
                fin >> temporary;
            } catch(ValidatorException& validatorException){
                fin.close();
                this->buffer.clear();
                throw ValidatorException();
            }
            this->buffer.push_back(temporary);
        }
    }
    fin.close();
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::dumpBufferToFile(){
    std::ofstream fout(pathToRepository);
    fout << "";
    if(this->buffer.size() > 0){
        for(int i = 0; i < this->buffer.size() - 1; i++){
            fout << this->buffer[i].toFormattedString() << std::endl;
        }
        if(this->buffer.size() > 0){
            fout << this->buffer[this->buffer.size() - 1].toFormattedString();
        }
    }
    fout.close();
    this->buffer.clear();
}

template<typename TemplateClass>
bool FileRepository<TemplateClass>::fileIsEmpty(std::ifstream &file){
    return file.peek() == std::ifstream::traits_type::eof();
}

template<typename TemplateClass>
std::vector<TemplateClass> FileRepository<TemplateClass>::asList(){
    loadBufferFromFile();
    std::vector<TemplateClass> temporaryBuffer(this->buffer);
    this->buffer.clear();
    return temporaryBuffer;
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::add(TemplateClass element){
    loadBufferFromFile();
    this->buffer.push_back(element);
    dumpBufferToFile();
}

template<typename TemplateClass>
TemplateClass& FileRepository<TemplateClass>::at(int index){
    loadBufferFromFile();
    if(index < this->buffer.size()){
        TemplateClass& element = this->buffer[index];
        this->buffer.clear();
        return element;
    } else {
        this->buffer.clear();
        throw RepositoryException();
    }
}

template<typename TemplateClass>
int FileRepository<TemplateClass>::getSize(){
    loadBufferFromFile();
    int size = this->buffer.size();
    this->buffer.clear();
    return size;
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::update(TemplateClass element){
    loadBufferFromFile();
    if(liveContainsElement(element)){
        this->buffer[indexOfElement(element)] = element;
        dumpBufferToFile();
    } else {
        dumpBufferToFile();
        throw RepositoryException();
    }
}

template <typename TemplateClass>
int FileRepository<TemplateClass>::indexOfElement(TemplateClass element) {
    int indexOfElementToRemove = -1;
    for(int i = 0; i < this->buffer.size(); i++){
        if(this->buffer[i] == element){
            indexOfElementToRemove = i;
        }
    }
    if(indexOfElementToRemove != -1){
        return indexOfElementToRemove;
    } else {
        throw RepositoryException();
    }
}

template<typename TemplateClass>
bool FileRepository<TemplateClass>::containsElement(TemplateClass element){
    loadBufferFromFile();
    bool contains = find(this->buffer.begin(), this->buffer.end(), element) != this->buffer.end();
    this->buffer.clear();
    return contains;
}

template<typename TemplateClass>
bool FileRepository<TemplateClass>::liveContainsElement(TemplateClass element){
    return find(this->buffer.begin(), this->buffer.end(), element) != this->buffer.end();
}

template<typename TemplateClass>
void FileRepository<TemplateClass>::remove(TemplateClass element){
    loadBufferFromFile();
    if(liveContainsElement(element)){
        this->buffer.erase(std::remove(this->buffer.begin(), this->buffer.end(), element), this->buffer.end());
        dumpBufferToFile();
    } else {
        dumpBufferToFile();
        throw RepositoryException();
    }

}

template<typename TemplateClass>
TemplateClass FileRepository<TemplateClass>::operator[](int index){
    loadBufferFromFile();
    if(index < this->buffer.size()){
        TemplateClass element = this->buffer[index];
        this->buffer.clear();
        return element;
    } else {
        this->buffer.clear();
        throw RepositoryException();
    }
}

template<typename TemplateClass>
FileRepository<TemplateClass>::FileRepository(){}


#endif // FILEREPOSITORY_H
