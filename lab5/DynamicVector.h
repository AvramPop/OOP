//
// Created by dani on 3/27/19.
//

#ifndef LAB5_DYNAMICVECTOR_H
#define LAB5_DYNAMICVECTOR_H


template <typename TemplateClass>
class DynamicVector{
    private:
        TemplateClass* buffer;
        int size;
        int capacity;
        void resize(double factor = 1.732);
        int indexOfElement(TemplateClass element) const;

    public:
        DynamicVector(int capacity = 10);
        ~DynamicVector();
        TemplateClass& operator[](int index);
        void add(TemplateClass newElement);
        void remove(TemplateClass elementToRemove);
        void update(TemplateClass elementToUpdate);
        int getSize();
        bool containsElement(TemplateClass element);


};

template <typename TemplateClass>
DynamicVector<TemplateClass>::DynamicVector(int capacity){
    this->size = 0;
    this->capacity = capacity;
    this->buffer = new TemplateClass[capacity];
}

template <typename TemplateClass>
DynamicVector<TemplateClass>::~DynamicVector(){
    delete[] this->buffer;
}

template <typename TemplateClass>
TemplateClass& DynamicVector<TemplateClass>::operator[](int index){
    return this->buffer[index];
}

template <typename TemplateClass>
void DynamicVector<TemplateClass>::add(TemplateClass newElement){
    if (this->size == this->capacity){
        this->resize();
    }
    this->buffer[this->size] = newElement;
    this->size++;
}

template <typename TemplateClass>
int DynamicVector<TemplateClass>::getSize(){
    return this->size;
}

template <typename TemplateClass>
void DynamicVector<TemplateClass>::resize(double factor){
    this->capacity *= factor;

    auto* newBuffer = new TemplateClass[this->capacity];
    for (int i = 0; i < this->size; i++){
        newBuffer[i] = this->buffer[i];
    }

    delete[] this->buffer;
    this->buffer = newBuffer;
}

template<typename TemplateClass>
void DynamicVector<TemplateClass>::remove(TemplateClass elementToRemove){
    if(containsElement(elementToRemove)){
        int indexOfElementToRemove = indexOfElement(elementToRemove);
        //delete this->buffer[indexOfElementToRemove];
        for(int i = indexOfElementToRemove; i < size - 1; i++){
            this->buffer[i] = this->buffer[i + 1];
        }
        this->size--;
    }
}

template<typename TemplateClass>
void DynamicVector<TemplateClass>::update(TemplateClass elementToUpdate){
    if(containsElement(elementToUpdate)){
        int indexOfElementToUpdate = indexOfElement(elementToUpdate);
        buffer[indexOfElementToUpdate] = elementToUpdate;
    }
}

template<typename TemplateClass>
bool DynamicVector<TemplateClass>::containsElement(TemplateClass element){
    return indexOfElement(element) != -1;
}

template<typename TemplateClass>
int DynamicVector<TemplateClass>::indexOfElement(TemplateClass element) const{
    int indexOfElementToRemove = -1;
    for(int i = 0; i < size; i++){
        if(buffer[i] == element){
            indexOfElementToRemove = i;
        }
    }
    return indexOfElementToRemove;
}

#endif //LAB5_DYNAMICVECTOR_H
