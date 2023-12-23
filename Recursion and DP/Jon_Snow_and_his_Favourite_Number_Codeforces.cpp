<<<<<<< HEAD
// https://codeforces.com/problemset/problem/768/C

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...)     { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)    for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

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

    int n, k, x;
    std::cin>>n>>k>>x;
    std::vector<int> frq(1100, 0);
    for(int i=0;i<n;i++){
        int num;
        std::cin>>num;
        frq[num]++;
    }
    while(k--){
        std::vector<int> temp(frq.begin(), frq.end());
        int sum = 0;
        for(int i=0;i<1100;i++){
            if(frq[i]){
                int y = i^x;
                int chng = frq[i]/2;
                if(sum%2 == 0 and frq[i]%2 == 1){++chng;}
                sum += frq[i];
                temp[i] -= chng;
                temp[y] += chng;
            }
        }
        frq = temp;
    }
    int max_ele = INT_MIN, min_ele = INT_MAX;
    for(int i=0;i<1100;i++){
        if(frq[i]){
            max_ele = std::max(max_ele, i);
            min_ele = std::min(min_ele, i);
        }
    }
    std::cout<<max_ele<<" "<<min_ele<<"\n";

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}
=======
// https://codeforces.com/problemset/problem/768/C

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...)     { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)    for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

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

    int n, k, x;
    std::cin>>n>>k>>x;
    std::vector<int> frq(1100, 0);
    for(int i=0;i<n;i++){
        int num;
        std::cin>>num;
        frq[num]++;
    }
    while(k--){
        std::vector<int> temp(frq.begin(), frq.end());
        int sum = 0;
        for(int i=0;i<1100;i++){
            if(frq[i]){
                int y = i^x;
                int chng = frq[i]/2;
                if(sum%2 == 0 and frq[i]%2 == 1){++chng;}
                sum += frq[i];
                temp[i] -= chng;
                temp[y] += chng;
            }
        }
        frq = temp;
    }
    int max_ele = INT_MIN, min_ele = INT_MAX;
    for(int i=0;i<1100;i++){
        if(frq[i]){
            max_ele = std::max(max_ele, i);
            min_ele = std::min(min_ele, i);
        }
    }
    std::cout<<max_ele<<" "<<min_ele<<"\n";

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
