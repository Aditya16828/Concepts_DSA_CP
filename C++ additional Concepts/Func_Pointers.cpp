<<<<<<< HEAD
#include<bits/stdc++.h>

void hello(){
    std::cout<<"Hello World.\n";
}

int fun(int n){
    std::cout<<"fun with "<<n<<"\n";
    return n;
}

void print(int v){
    std::cout<<"Value is "<<v<<"\n";
}

void for_each(std::vector<int> &v, void(*func)(int)){
    for(auto value : v)
    func(value);
}

int main()
{
    int x = 10;
    int *p = &x;
    std::cout<<p<<", "<<x<<"\n";
    void (*ptr)() = hello;
    //auto ptr = hello;
    ptr();
    std::cout<<ptr<<"\n";
    std::cout<<*ptr<<"\n";

    int(*fun_ptr)(int) = fun;
    fun_ptr(8);

    std::vector<int> v;
    v.push_back(1);
    v.push_back(26);
    v.push_back(34);
    v.push_back(56);
    for_each(v, print);
    return 0;
}
=======
#include<bits/stdc++.h>

void hello(){
    std::cout<<"Hello World.\n";
}

int fun(int n){
    std::cout<<"fun with "<<n<<"\n";
    return n;
}

void print(int v){
    std::cout<<"Value is "<<v<<"\n";
}

void for_each(std::vector<int> &v, void(*func)(int)){
    for(auto value : v)
    func(value);
}

int main()
{
    int x = 10;
    int *p = &x;
    std::cout<<p<<", "<<x<<"\n";
    void (*ptr)() = hello;
    //auto ptr = hello;
    ptr();
    std::cout<<ptr<<"\n";
    std::cout<<*ptr<<"\n";

    int(*fun_ptr)(int) = fun;
    fun_ptr(8);

    std::vector<int> v;
    v.push_back(1);
    v.push_back(26);
    v.push_back(34);
    v.push_back(56);
    for_each(v, print);
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
