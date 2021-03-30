//
// Created by Sakura on 3/29/2021.
//

#ifndef A45_913ALICEHINCU_DYNAMICARRAY_H
#define A45_913ALICEHINCU_DYNAMICARRAY_H


#include <string>
#include <exception>
template <class TypeOfElement>
class DynamicArray {

private:
    int capacity{};
    int size{};
    int currentElementIndex{}; // for iterating

    TypeOfElement *elements;
    void resizeArray(int capacity);


public:
    DynamicArray();
    // explicit constructor
    explicit DynamicArray(int capacity = 10);

    // copy constructor
    DynamicArray(const DynamicArray& copyArray);

    // "=" overwrite
    DynamicArray& operator=(const DynamicArray& copyArray);

    // add element at the end of container
    void addElement(TypeOfElement newElement);

    // add element to a certain position
    void addElementToPosition(TypeOfElement newElement, int position);

    // remove element from a certain position
    void removeElementFromPosition(int position);

    // get the element from the container at the given position
    TypeOfElement getElement(int position);

    // set the element from the container at the given position
    void setElement(TypeOfElement newElement, int position);

    // get size of container
    [[nodiscard]] int getSize() const;

    // for iterator:
    TypeOfElement getCurrentElement();

    // destructor
    ~DynamicArray();

};


//explicit constructor
template<class TypeOfElement>
DynamicArray<TypeOfElement>::DynamicArray(int capacity) {
    this->capacity = capacity;
    this->size = 0;
    this->elements = new TypeOfElement[this->capacity];
    this->currentElementIndex = 0;
}

//copy constructor
template<class TypeOfElement>
DynamicArray<TypeOfElement>::DynamicArray(const DynamicArray &copyArray) {
    size = copyArray.size;
    capacity = copyArray.capacity;
    elements = new TypeOfElement[capacity];
    for (int i = 0; i < size; ++i) {
        elements[i] = copyArray.elements[i];
    }
    currentElementIndex = copyArray.currentElementIndex;
}

// =
template<class TypeOfElement>
DynamicArray<TypeOfElement>& DynamicArray<TypeOfElement>::operator=(const DynamicArray<TypeOfElement> &copyArray) {
    if (this == &copyArray) {
        return *this;
    }
    size = copyArray.size;
    capacity = copyArray.capacity;

    delete [] elements;
    elements = new TypeOfElement[this->capacity];
    for (int i = 0; i < size; ++i) {
        elements[i] = copyArray.elements[i];
    }
    return *this;
}

// add element at the end
template<class TypeOfElement>
void DynamicArray<TypeOfElement>::addElement(TypeOfElement newElement) {
    if (size == capacity) {
        resizeArray(2 * capacity);
    }
    elements[size++] = newElement;
}


// add element to a position
template<class TypeOfElement>
void DynamicArray<TypeOfElement>::addElementToPosition(TypeOfElement newElement, int position) {
    if (position > size or position < 0) {
        throw std::exception();
    }
    if (size == capacity) {
        resizeArray(2 * capacity);
    }

    for (int i = size; i > position; ++i) {
        elements[i] = elements[i - 1];
    }
    size++;
    elements[position] = newElement;
}


template<class TypeOfElement>
void DynamicArray<TypeOfElement>::removeElementFromPosition(int position) {
    if (position >= size or position < 0) {
        throw std::exception();
    }
    if (size == capacity / 4) {
        resizeArray(capacity / 2);
    }
    size--;
    for (int i = position; i < size; ++i) {
        elements[i] = elements[i + 1];
    }
}


template <class TypeOfElement>
TypeOfElement DynamicArray<TypeOfElement>::getCurrentElement()  {
    if (currentElementIndex == size) {
        currentElementIndex = 0;
    }
    return elements[currentElementIndex++];
}



template<class TypeOfElement>
int DynamicArray<TypeOfElement>::getSize() const {
    return size;
}


template<class TypeOfElement>
void DynamicArray<TypeOfElement>::setElement(TypeOfElement newElement, int position) {
    if (position >= size or position < 0) {
        throw std::exception();
    }
    elements[position] = newElement;
}

template<class TypeOfElement>
TypeOfElement DynamicArray<TypeOfElement>::getElement(int position) {
    if (position >= size or position < 0) {
        throw std::exception();
    }
    return elements[position];
}


template<class TypeOfElement>
void DynamicArray<TypeOfElement>::resizeArray(int newCapacity) {
    capacity = newCapacity;
    auto * auxiliaryArray = new TypeOfElement[capacity];
    for (int i = 0; i < size; ++i) {
        auxiliaryArray[i] = elements[i];
    }
    delete [] elements;
    elements = auxiliaryArray;
}


template<class TypeOfElement>
DynamicArray<TypeOfElement>::~DynamicArray() {
    delete [] this->elements;
    this->size = 0;
}

template<class TypeOfElement>
DynamicArray<TypeOfElement>::DynamicArray(): capacity{10}, size{0}, currentElementIndex{0} {

}



#endif //A45_913ALICEHINCU_DYNAMICARRAY_H
