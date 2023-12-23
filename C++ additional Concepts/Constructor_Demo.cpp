#include <bits/stdc++.h>
#define ll long long int

void file_io() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
}

class ComplexNumber {
public:
    int real, img;
    int* ptr;

    /*ComplexNumber() {
        this->real = 0;
        this->img = 0;
    }*/
    // another way to write default constructor
    ComplexNumber() : real(0), img(0) {}

    ComplexNumber(int real, int img) {
        this->real = real;
        this->img = img;
    }

    ComplexNumber(ComplexNumber& s) {
        this->real = s.real;
        this->img = s.img;
        this->ptr = new int;
        *ptr = *(s.ptr);
    }

    int getReal() {
        return this->real;
    }
    int getReal(int x) {
        return this->real - x;
    }
    void display(float x) {
        std::cout << x << "\n";
    }
    void display(int x) {
        std::cout << x << "\n";
    }
    int show_real();
};

int ComplexNumber::show_real() {
    real = 10;
    return real;
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_io();

    ComplexNumber c(67, 89);
    ComplexNumber c2;

    c.display(1.1f);
    c.getReal();
    c.getReal(1);
    int x = 10;
    c.ptr = &x;

    ComplexNumber m;
    m = c; // Copy constructor -> member function that initializes an object using another object of the same class
    /*
    2 types of copy constructor: shallow copy and deep copy
    If we do not define our own copy constructor, by default shallow copy is done.
    What is shallow copy??
        An obj. is created by simply copying all the data of all variable of one obj.
    */
    std::cout << m.real << ", " << m.img << "\n";
    m.real = 10;
    std::cout << m.real << ", " << m.img << "\n";
    std::cout << c.real << ", " << c.img << "\n";

    std::cout << c.ptr << ", " << m.ptr << "\n";
    std::cout << *c.ptr << ", " << *m.ptr << "\n";


#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}

// Polymorphism: poly + morph => many forms, one thing can have different forms
/* 2 types: Compile-time plymorphism(early binding/static binding)
            Runtime Polymorphism
*/