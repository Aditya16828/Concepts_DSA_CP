<<<<<<< HEAD
/*
Create a class Product, enter some random values of n products in an array and sort it based on price.
*/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}

void file_i_o() {
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

class Product{
    std::string name, desc;
    double price;
public:
    Product(std::string name, std::string desc, double price) : 
        name(name), desc(desc), price(price){}
    void getter(){
        std::cout<<"Name: "<<name<<"\nDescription: "<<desc<<"\nPrice: "<<price<<"\n";
    }

    double get_price(){
        return price;
    }

    bool operator < (const Product &p) const {
        return this->price < p.price;
    }
};

bool cmp(Product &p1, Product &p2){
    return p1.get_price() < p2.get_price();
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    std::cin>>n;
    std::vector<Product> v;
    v.reserve(n);
    for(int i=0;i<n;i++){
        std::string name, desc;
        double cost;
        std::cin>>name>>desc>>cost;
        v.emplace_back(name, desc, cost);
    }
    //std::sort(v.begin(), v.end(), cmp);
    std::sort(v.begin(), v.end());
    for(auto &i:v){
        i.getter();
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
=======
/*
Create a class Product, enter some random values of n products in an array and sort it based on price.
*/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}

void file_i_o() {
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(0); 
    std::cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

class Product{
    std::string name, desc;
    double price;
public:
    Product(std::string name, std::string desc, double price) : 
        name(name), desc(desc), price(price){}
    void getter(){
        std::cout<<"Name: "<<name<<"\nDescription: "<<desc<<"\nPrice: "<<price<<"\n";
    }

    double get_price(){
        return price;
    }

    bool operator < (const Product &p) const {
        return this->price < p.price;
    }
};

bool cmp(Product &p1, Product &p2){
    return p1.get_price() < p2.get_price();
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    std::cin>>n;
    std::vector<Product> v;
    v.reserve(n);
    for(int i=0;i<n;i++){
        std::string name, desc;
        double cost;
        std::cin>>name>>desc>>cost;
        v.emplace_back(name, desc, cost);
    }
    //std::sort(v.begin(), v.end(), cmp);
    std::sort(v.begin(), v.end());
    for(auto &i:v){
        i.getter();
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
