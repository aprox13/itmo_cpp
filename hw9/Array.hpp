#pragma once

#include "Array.h"


template<class T>
Array<T>::Array() {
    mBase = 0;
    mSize = 0;
}

template<class T>
Array<T>::Array(size_t size, const T& value) : mSize(size) {
    mBase = new T[size];
    for (int i = 0; i < size; i++) {
        new(mBase + i) T(value);
    }
}

template<class T>
Array<T>::Array(const Array& from) : mSize(from.mSize) {
    mBase = new T[from.size()];
    for (int i = 0; i < mSize; i++) {
        new(mBase + i) T(from[i]);
    }
}

template<class T>
Array<T>::Array(Array&& source) noexcept : mSize(source.mSize), mBase(source.mBase) {
    source.mSize = 0;
    source.mBase = nullptr;
}

template<class T>
Array<T>::~Array() {
    delete[] mBase;
    mBase = NULL;
}

template<class T>
Array<T>& Array<T>::operator=(const Array& right) {
    if (this != &right) {
        *this = Array(right);
    }
    return *this;
}

template<class T>
Array<T>& Array<T>::operator=(Array&& source) noexcept {
    if (&source != this) {
        delete[] mBase;
        mBase = source.mBase;
        mSize = source.mSize;
        source.mSize = 0;
        source.mBase = nullptr;

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

