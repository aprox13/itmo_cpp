#include "String.h"


int String::size(const char* base) {
    int i = 0;
    while (base[i] != '\0') {
        i++;
    }
    return i;
}

String::String(const char* str) {
    mSize = size(str);
    int i = 0;
    mStr = new char[mSize + 1];
    while (str[i] != '\0') {
        mStr[i] = str[i];
        i++;
    }
    mStr[mSize] = '\0';
}

String::String(const int size, const char filter) {
    mSize = size;
    mStr = new char[size + 1];
    for (int i = 0; i < size; i++) {
        mStr[i] = filter;
    }
    mStr[size] = '\0';
}

String::~String() {
    delete[] mStr;
}

String& String::operator=(const String& another) {
    if (this != &another) {
        mSize = another.length();
        delete[] mStr;
        int i = 0;
        mStr = new char[mSize + 1];
        while (another.mStr[i] != '\0') {
            mStr[i] = another.mStr[i];
            i++;
        }
        mStr[mSize] = '\0';
    }
    return *this;
}

void String::append(const String& another) {
    int newSize = another.length() + mSize;
    auto* newStr = new char[newSize + 1];
    int i = 0;
    while (mStr[i] != '\0') {
        newStr[i] = mStr[i];
        i++;
    }
    int j = 0;
    while (another.mStr[j] != '\0') {
        newStr[i] = another.mStr[j];
        i++;
        j++;
    }
    newStr[newSize] = '\0';
    delete[] mStr;
    mStr = newStr;
    mSize = newSize;
}

int String::length() const {
    return mSize;
}


std::ostream& operator<<(std::ostream& os, const String& data) {
    os << data.mStr;
    return os;
}



