#pragma once

#include <cstdlib>


//https://books.google.ru/books?id=n9VEG2Gp5pkC&pg=PA10&lpg=PA10&dq=%22The+only+portable+way+of+using+templates+at+the+moment+is+to+implement+them+in+header+files+by+using+inline+functions.%22&source=bl&ots=Ref8pl8dPX&sig=t4K5gvxtBblpcujNxodpwMfei8I&hl=en&ei=qkR6TvbiGojE0AHq4IzqAg&sa=X&oi=book_result&ct=result&redir_esc=y#v=onepage&q=%22The%20only%20portable%20way%20of%20using%20templates%20at%20the%20moment%20is%20to%20implement%20them%20in%20header%20files%20by%20using%20inline%20functions.%22&f=false
template<class T>
class Array {

public:

    Array();
    explicit Array(size_t size, const T& value = T());
    Array(const Array&);
    Array(Array&&) noexcept;
    ~Array();

    Array& operator=(const Array&);
    Array& operator=(Array&&) noexcept;
    size_t size() const;
    const T& operator[](size_t) const;
    T& operator[](size_t);

private:
    T* mBase;
    size_t mSize;
};


#include "Array.hpp"

