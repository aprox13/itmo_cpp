#pragma once
//#include "Array.h"



template<class T>
Array<T>::Array() {
    mBase = nullptr;
    mSize = 0;
}

template<class T>
Array<T>::Array(size_t size, const T& value) : mSize(size) {
    mBase = static_cast<T*>(operator new[](size * sizeof(T)));
    for (int i = 0; i < size; i++) {
        new(mBase + i) T(value);
    }
}

template<class T>
Array<T>::Array(const Array& from) : mSize(from.mSize) {
    mBase = static_cast<T*>(operator new[](mSize * sizeof(T)));
    for (int i = 0; i < mSize; i++) {
        new(mBase + i) T(from[i]);
    }
}

template<class T>
Array<T>::~Array() {
    for(int i = 0; i < size(); i++){
        mBase[i].~T();
    }
    operator delete[](mBase);
}

template<class T>
Array<T>& Array<T>::operator=(const Array& right) {
    if (this != &right) {
        delete[] mBase;
        mSize = right.mSize;
        mBase = static_cast<T*>(operator new[](mSize * sizeof(T)));
        for (int i = 0; i < size(); i++) {
            new(mBase + i) T(right[i]);
        }
    }
    return *this;
}

template<class T>
size_t Array<T>::size() const {
    return mSize;
}

template<class T>
const T& Array<T>::operator[](size_t index) const {
    return mBase[index];
}

template<class T>
T& Array<T>::operator[](size_t index) {
    return mBase[index];
}

template<class T, class Comparator>
T& minimum(Array<T> base, Comparator cmp) {
    size_t minIndex = 0;
    for (size_t i = 1; i < base.size(); i++) {
        if (cmp(base[i], base[minIndex])) {
            minIndex = i;
        }
    }
    return base[minIndex];
}


template<class T>
void flatten(const T& element, std::ostream& out) {
    out << element << " ";
}

template<class T>
void flatten(const Array<T>& array, std::ostream& out) {
    for (int i = 0; i < array.size(); i++) {
        flatten(array[i], out);
    }
}