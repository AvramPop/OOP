#ifndef INMEMORYREPOSITORY_H
#define INMEMORYREPOSITORY_H

#include <vector>
#include "Exception.h"
#include "VictimFile.h"
#include "Repository.h"

template <typename TemplateClass>
class InMemoryRepository : public Repository<TemplateClass> {
public:
    int indexOfElement(TemplateClass element) override {
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
    virtual InMemoryRepository<TemplateClass>* cloneImplementation() const override { return new InMemoryRepository(*this);}
    InMemoryRepository() {}
    void add(TemplateClass element) override {
        this->buffer.push_back(element);
    }
    std::vector<TemplateClass> asList() override{
        std::vector<TemplateClass> temporaryBuffer(this->buffer);
        return temporaryBuffer;
    }
    bool containsElement(TemplateClass element) override{
        return find(this->buffer.begin(), this->buffer.end(), element) != this->buffer.end();
    }
    void remove(TemplateClass element) override{
        if(containsElement(element)){
            this->buffer.erase(std::remove(this->buffer.begin(), this->buffer.end(), element), this->buffer.end());
        } else {
            throw RepositoryException();
        }
    }
    void update(TemplateClass element) override{
        if(containsElement(element)){
            this->buffer[indexOfElement(element)] = element;
        } else {
            throw RepositoryException();
        }
    }
    int getSize() override{
        return this->buffer.size();
    }
    TemplateClass& at(int index) override{
        if(index < this->buffer.size()){
            TemplateClass& element = this->buffer[index];
            return element;
        } else {
            throw RepositoryException();
        }
    }
    TemplateClass operator[](int index) override{
        if(index < this->buffer.size()){
            TemplateClass element = this->buffer[index];
            return element;
        } else {
            throw RepositoryException();
        }
    }
};

#endif // INMEMORYREPOSITORY_H
