<<<<<<< HEAD
#include<bits/stdc++.h>

void for_each(std::vector<int> &v, void(*func_ptr)(int)){
    for(auto i:v){
        func_ptr(i);
    }
}

int main(){
    std::vector<int> v;
    v.push_back(1);
    v.push_back(26);
    v.push_back(34);
    v.push_back(56);
    //int x = 9;
    for_each(v, [](int v){std::cout<<"Value from lambda "<<v<<"\n";});
    return 0;
=======
#include<bits/stdc++.h>

void for_each(std::vector<int> &v, void(*func_ptr)(int)){
    for(auto i:v){
        func_ptr(i);
    }
}

int main(){
    std::vector<int> v;
    v.push_back(1);
    v.push_back(26);
    v.push_back(34);
    v.push_back(56);
    //int x = 9;
    for_each(v, [](int v){std::cout<<"Value from lambda "<<v<<"\n";});
    return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}