//
// Created by dani on 4/15/19.
//

#ifndef LAB5_REPOSITORY_H
#define LAB5_REPOSITORY_H


#include <vector>
#include <algorithm>

template <typename TemplateClass>
class Repository {
private:
    int indexOfElement(TemplateClass element);
    vector<TemplateClass> buffer;
public:
    void add(TemplateClass& element);
    vector<TemplateClass> getList();
    bool containsElement(TemplateClass element);
    void remove(TemplateClass element);
    void update(TemplateClass element);
    int getSize();
    TemplateClass& operator[](int index);

};

template <typename TemplateClass>
void Repository<TemplateClass>::add(TemplateClass& element){
    buffer.push_back(element);
}

template <typename TemplateClass>
vector<TemplateClass> Repository<TemplateClass>::getList(){
    return buffer;
}

template <typename TemplateClass>
bool Repository<TemplateClass>::containsElement(TemplateClass element){
    return find(buffer.begin(), buffer.end(), element) != buffer.end();
}

template <typename TemplateClass>
void Repository<TemplateClass>::remove(TemplateClass element){
    if(containsElement(element)){
        buffer.erase(std::remove(buffer.begin(), buffer.end(), element), buffer.end());
    }
}

template <typename TemplateClass>
void Repository<TemplateClass>::update(TemplateClass element){
    if(containsElement(element)){
        buffer[indexOfElement(element)] = element;
    }
}

template <typename TemplateClass>
int Repository<TemplateClass>::indexOfElement(TemplateClass element) {
    int indexOfElementToRemove = -1;
    for(int i = 0; i < buffer.size(); i++){
        if(buffer[i] == element){
            indexOfElementToRemove = i;
        }
    }
    return indexOfElementToRemove;
}

template <typename TemplateClass>
int Repository<TemplateClass>::getSize(){
    return buffer.size();
}

template <typename TemplateClass>
TemplateClass& Repository<TemplateClass>::operator[](int index){
    if(index < getSize()){
        return buffer[index];
    }
    throw exception();
}


#endif //LAB5_REPOSITORY_H
