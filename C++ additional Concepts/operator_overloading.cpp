#include <bits/stdc++.h>
#include <typeinfo>
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

class Test {
    int count;
    int arr[100];
public:
    Test() :count(0) {}

    Test(int c) :count(c) {}

    int get_count() const {
        return this->count;
    }
    void set_count(int c) {
        this->count = c;
    }

    // overload unary operators ++(prefix, postfix), --
    // case 1: overload prefix ++
    Test operator ++() {
        std::cout << "Called prefix\n";
        ++this->count;
        /*Test retval;
        retval.count = this->count;
        return retval;*/
        return Test(this->count);
    }

    // case 2: overload postfix ++
    Test operator ++(int) {
        std::cout << "Called postfix\n";
        return Test(this->count++);
    }

    // case 3: Overload Binary operators
    Test operator +(Test t) {
        return Test(this->count + t.count);
    }

    // case 4: Overload comparison operator
    bool operator < (Test v) {
        bool b = this->count < v.count;
        return b;
    }

    // case 5: overload assignment operator
    void operator +=(Test& v) {
        this->count += v.count;
    }

    // case 6: overload subscript operator ([])
    int& operator [](int n) { // int& bcz we have to return the bucket and not value(always)
        if (n < 0 or n >= 100) exit(1);
        return this->arr[n];
    }

    /*
    Operators we cannot overload:
        1. (.) dot operator
        2. (?:) ternary operator
        3. (::) scope resolution operator
        4. (.*) pointer to member operator
        5. (sizeof) size of operator
        6. (typeid) typeid operator
    */
};

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_io();

    Test t;
    std::cout << t.get_count() << "\n";
    Test x = ++t;
    //Test x = t++;
    std::cout << t.get_count() << "\n";
    std::cout << x.get_count() << "\n";

    x.set_count(3);
    Test c = x + t; // x asks to add t, t is passed as argument to overloaded + operator
    std::cout << c.get_count() << "\n";

    bool b = c < t;
    std::cout << b << "\n";

    c += t;
    std::cout << t.get_count() << "\n";
    std::cout << c.get_count() << "\n";

    c[2] = 10;

    // typeid operator demo
    int i, j;
    const std::type_info& typei = typeid(i);
    const std::type_info& typej = typeid(j);
    std::cout << (typei == typej) << "\n";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}