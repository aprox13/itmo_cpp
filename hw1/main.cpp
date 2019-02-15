/*
 * 1. Write  a Program to demonstrate functions.
 * 2. Write  a Program to demonstrate function overloading.
 * 3. Write  a Program to demonstrate default arguments.
 * 4. Write  a Program to demonstrate pass by value, pass by reference and return by reference.
 * 5. Write  a Program to demonstrate classes and objects.
 * 6. Write  a Program to demonstrate  constructors.
 */
#include <iostream>
#include <string>

using namespace std;


void function() {
    cout << "Hello world!" << endl;
}

int function1(){
    cout << "return 0" << endl;
    return 0;
}

void function(string &name) {
    cout << "Hello, " << name << endl;
}

void default_param(int a = 10) {
    cout << "function parameter is " << a << endl;
}

void val_swap(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void ref_swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}


class Object {
private:
    int a;
public:
    Object() : a(0) {
        cout << "Empty constructor(Object)" << endl;
    }

    explicit Object(int param) : a(param) {
        cout << "Constructor with param(Object)" << endl;
    }

    void hellow(){
        cout << "Hellow" << endl;
    }

    void info(){
        cout << "a = " << a << endl;
    }
};

class Hellow: public Object{
public:
    Hellow(): Object(){

    }
};


int main() {

    cout << "function demo" << endl;
    function();
    cout << "###\noverloading function demo" << endl;
    function("mr. X"); // function overloading
    cout << "###\ndefault params demo" << endl;
    cout << "def_param() -> ";
    default_param();
    cout << "def_param(10280) -> ";
    default_param(10280);
    cout << "###\npass by value, pass by reference and return by reference" << endl;
    int a = 5, b = 8;
    cout << "before a = " << a << ", " << "b = " << b << endl;
    cout << "after val_swap(a, b) -> ";
    val_swap(a, b);
    cout << "a = " << a << ", " << "b = " << b << endl;
    cout << "after ref_swap(a, b) -> ";
    ref_swap(a, b);
    cout << "a = " << a << ", " << "b = " << b << endl;
    cout << "###\nclasses" << endl;
    Object object1(10);
    object1.info();
    Object object;
    object.info();
    Hellow hellow;
    hellow.hellow();
    return 0;
}