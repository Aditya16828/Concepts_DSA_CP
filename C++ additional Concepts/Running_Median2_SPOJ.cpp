<<<<<<< HEAD
// https://www.spoj.com/problems/RMID2/
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

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int t;
    std::cin>>t;
    while(t--){
        std::priority_queue<ll> left_max;
        std::priority_queue<ll, std::vector<ll>, std::greater<ll>> right_min;
        while(true){
            int n;
            std::cin>>n;
            if(n == 0) break;
            if(n == -1){
                std::cout<<left_max.top()<<"\n";
                left_max.pop();
                if(left_max.size() != right_min.size()){
                    int el = right_min.top();
                    right_min.pop();
                    left_max.push(el);
                }
                continue;
            }
            if(left_max.empty()){
                left_max.push(n);
                continue;
            }
            if(left_max.size() == right_min.size()){
                if(n < left_max.top()){
                    left_max.push(n);
                } else {
                    right_min.push(n);
                    int el = right_min.top();
                    right_min.pop();
                    left_max.push(el);
                }
            } else {
                if(n <= left_max.top()){
                    left_max.push(n);
                    int el = left_max.top();
                    left_max.pop();
                    right_min.push(el);
                } else {
                    right_min.push(n);
                }
            }
        }
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
=======
// https://www.spoj.com/problems/RMID2/
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

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int t;
    std::cin>>t;
    while(t--){
        std::priority_queue<ll> left_max;
        std::priority_queue<ll, std::vector<ll>, std::greater<ll>> right_min;
        while(true){
            int n;
            std::cin>>n;
            if(n == 0) break;
            if(n == -1){
                std::cout<<left_max.top()<<"\n";
                left_max.pop();
                if(left_max.size() != right_min.size()){
                    int el = right_min.top();
                    right_min.pop();
                    left_max.push(el);
                }
                continue;
            }
            if(left_max.empty()){
                left_max.push(n);
                continue;
            }
            if(left_max.size() == right_min.size()){
                if(n < left_max.top()){
                    left_max.push(n);
                } else {
                    right_min.push(n);
                    int el = right_min.top();
                    right_min.pop();
                    left_max.push(el);
                }
            } else {
                if(n <= left_max.top()){
                    left_max.push(n);
                    int el = left_max.top();
                    left_max.pop();
                    right_min.push(el);
                } else {
                    right_min.push(n);
                }
            }
        }
    }

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
