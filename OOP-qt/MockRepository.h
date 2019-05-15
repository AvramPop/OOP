#ifndef MOCKREPOSITORY_H
#define MOCKREPOSITORY_H



#include <vector>
#include "Exception.h"
#include "VictimFile.h"
#include "Repository.h"

template <typename TemplateClass>
class MockRepository : public Repository<TemplateClass> {
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
    virtual MockRepository<TemplateClass>* cloneImplementation() const override { return new MockRepository(*this);};
    MockRepository() {
        VictimFile testFile1("testName1 surname1", "placeOfOrigin1", 1, "photo1");
        VictimFile testFile2("testName2 surname2", "placeOfOrigin2", 2, "photo2");
        VictimFile testFile3("testName3 surname3", "placeOfOrigin3", 3, "photo3");
        VictimFile testFile4("testName4 surname4", "placeOfOrigin4", 4, "photo4");
        VictimFile testFile5("testName5 surname5", "placeOfOrigin5", 5, "photo5");
        VictimFile testFile6("testName6 surname6", "placeOfOrigin6", 6, "photo6");
        VictimFile testFile7("testName7 surname7", "placeOfOrigin7", 7, "photo7");
        VictimFile testFile8("testName8 surname8", "placeOfOrigin8", 8, "photo8");
        VictimFile testFile9("testName9 surname9", "placeOfOrigin9", 9, "photo9");
        this->buffer.push_back(testFile1);
        this->buffer.push_back(testFile2);
        this->buffer.push_back(testFile3);
        this->buffer.push_back(testFile4);
        this->buffer.push_back(testFile5);
        this->buffer.push_back(testFile6);
        this->buffer.push_back(testFile7);
        this->buffer.push_back(testFile8);
        this->buffer.push_back(testFile9);
    }
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


#endif // MOCKREPOSITORY_H
