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
    /**
     * Initialise Dynamic vector with default capacity of 10.
     * @param capacity
     */
    DynamicVector(int capacity = 10);
    ~DynamicVector();
    /**
     * Overwrite access operator to return element at index.
     */
    TemplateClass& operator[](int index);
    /**
     * Add element to vector if it doesn't exist according to object equality.
     * @param newElement
     */
    void add(TemplateClass& newElement);
    /**
     * Remove element if it exists in vector.
     */
    void remove(TemplateClass elementToRemove);
    /**
     * Update element given by equality testing.
     */
    void update(TemplateClass& elementToUpdate);
    /**
     * Get current size of vector (aka number of elements).
     */
    int getSize();
    /**
     * Checks whether element is contained by vector.
     */
    bool containsElement(TemplateClass element);

    DynamicVector(const DynamicVector& baseVector);

    DynamicVector& operator=(const DynamicVector& baseVector);

public:
    class Iterator {
    private:
        TemplateClass* current;
    public:
        Iterator(TemplateClass* beginning){
            current = beginning;
        }

        Iterator operator++(){
            this->current++;
            return *this;
        }

        Iterator operator++(int){
            TemplateClass* actual = current;
            this->current++;
            return Iterator{actual};
        }

        TemplateClass operator*(){
            return *current;
        }

        bool operator!=(Iterator otherIterator){
            return current != otherIterator.current;
        }
    };

    Iterator begin(){
        return Iterator(buffer);
    }

    Iterator end(){
        return Iterator(buffer + size);
    }


};

template <typename TemplateClass>
DynamicVector<TemplateClass>& DynamicVector<TemplateClass>::operator=(const DynamicVector<TemplateClass>& baseVector){
    if (this == &baseVector){
        return *this;
    }
    this->size = baseVector.size;
    this->capacity = baseVector.capacity;

    delete[] this->buffer;
    this->buffer = new TemplateClass[this->capacity];
    for (int i = 0; i < this->size; i++){
        this->buffer[i] = baseVector.buffer[i];
    }
    return *this;
}


template <typename TemplateClass>
DynamicVector<TemplateClass>::DynamicVector(const DynamicVector<TemplateClass>& baseVector){
    this->size = baseVector.size;
    this->capacity = baseVector.capacity;
    this->buffer = new TemplateClass[this->capacity];
    for (int i = 0; i < this->size; i++)
        this->buffer[i] = baseVector.buffer[i];
}

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
void DynamicVector<TemplateClass>::add(TemplateClass& newElement){
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
        for(int i = indexOfElementToRemove; i < size - 1; i++){
            this->buffer[i] = this->buffer[i + 1];
        }
        this->size--;
    }
}

template<typename TemplateClass>
void DynamicVector<TemplateClass>::update(TemplateClass& elementToUpdate){
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