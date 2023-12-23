<<<<<<< HEAD
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

class Test {
public:
    int x;
    //static int y;
    mutable std::string LOG; // helps to by pass const

    int getX() const { // won't be able to reassign the data to non-static data members
        //y = 9;
        LOG = "test";
        std::cout << "With const\n";
        return x;
    }

    int getX() {
        std::cout << "Without const\n";
        return x;
    }
    // after overloading getX() no error will be there after removing const from parameter of fun().
    // the output will change

    void setX(int x) {
        this->x = x;
    }
};

void func(const int x) {
    //x = 10; // error
}

void fun(const Test& t) {
    std::cout << t.getX() << "\n";
}
// Removing the const from getX() will give error;
// Reason: compiler assumes that no property of t will be updated but getX will not anymore guarantee abt that.
// also not be able to call setX()

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_io();

    const int MAX_VAL = 1000;
    std::cout << MAX_VAL << "\n";
    //MAX_VAL = 99; // gives error
    //MAX_VAL++; // gives error
    //MAX_VAL += 1;// gives error
    //MAX_VAL = MAX_VAL + 1; // gives error

    const int* p = &MAX_VAL;
    //*ptr = 2;
    int* ptr = new int;
    *ptr = 2;

    ptr = (int*)&MAX_VAL;
    *ptr = 10;
    std::cout << ptr << " " << p << "\n";
    std::cout << *ptr << " " << *p << "\n";
    std::cout << MAX_VAL << "\n";
    std::cout << &MAX_VAL << "\n";

    std::cout << "******************\n";

    //const int* a = new int;
    //int const* a = new int;
    // *a = 10; // not allow to update the value

    int const* a = new int;
    // or const int *a = new int;
    a = (int*)&MAX_VAL;

    int* const b = new int;
    *b = 2;
    std::cout << *b << "\n";
    // b = (int*)&MAX_VAL; // with this we won't be able to reassign a new bucket but we can change the value of bucket
    const int* k; // with this we can't change the content but we can reassign.
    int const* l; // with this we can't change the content but we can reassign.

    Test t;
    fun(t);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}

=======
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

class Test {
public:
    int x;
    //static int y;
    mutable std::string LOG; // helps to by pass const

    int getX() const { // won't be able to reassign the data to non-static data members
        //y = 9;
        LOG = "test";
        std::cout << "With const\n";
        return x;
    }

    int getX() {
        std::cout << "Without const\n";
        return x;
    }
    // after overloading getX() no error will be there after removing const from parameter of fun().
    // the output will change

    void setX(int x) {
        this->x = x;
    }
};

void func(const int x) {
    //x = 10; // error
}

void fun(const Test& t) {
    std::cout << t.getX() << "\n";
}
// Removing the const from getX() will give error;
// Reason: compiler assumes that no property of t will be updated but getX will not anymore guarantee abt that.
// also not be able to call setX()

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_io();

    const int MAX_VAL = 1000;
    std::cout << MAX_VAL << "\n";
    //MAX_VAL = 99; // gives error
    //MAX_VAL++; // gives error
    //MAX_VAL += 1;// gives error
    //MAX_VAL = MAX_VAL + 1; // gives error

    const int* p = &MAX_VAL;
    //*ptr = 2;
    int* ptr = new int;
    *ptr = 2;

    ptr = (int*)&MAX_VAL;
    *ptr = 10;
    std::cout << ptr << " " << p << "\n";
    std::cout << *ptr << " " << *p << "\n";
    std::cout << MAX_VAL << "\n";
    std::cout << &MAX_VAL << "\n";

    std::cout << "******************\n";

    //const int* a = new int;
    //int const* a = new int;
    // *a = 10; // not allow to update the value

    int const* a = new int;
    // or const int *a = new int;
    a = (int*)&MAX_VAL;

    int* const b = new int;
    *b = 2;
    std::cout << *b << "\n";
    // b = (int*)&MAX_VAL; // with this we won't be able to reassign a new bucket but we can change the value of bucket
    const int* k; // with this we can't change the content but we can reassign.
    int const* l; // with this we can't change the content but we can reassign.

    Test t;
    fun(t);

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
    return 0;
}

>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
// no speed optimisations attained by using const(no guarantees)