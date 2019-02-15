#pragma once

#include <iostream>

class String {
public:
    String(const char* str);

    String(const int size, const char filter);

    String& operator=(const String& another);

    ~String();

    void append(const String& another);

    int length() const;

    friend std::ostream& operator<<(std::ostream& os, const String& data);

private:
    int   mSize;
    char* mStr;


    int  size(const char* base);


};

