<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
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

// std::vector<std::vector<ll>> dp;
// ll minCost(int i, int j, std::vector<int> &arr){
//     if(j-i+1 == 2) return 0;
//
//     if(dp[i][j] != -1) return dp[i][j];
//
//     int n = arr.size();
//     ll res = inf;
//     for(int k=i+1;k<j;k++){
//         res = std::min(res, minCost(i, k, arr) + minCost(k, j, arr) + (arr[i]*arr[k]*arr[j]));
//     }
//     return dp[i][j] = res;
// }

ll minCost(std::vector<int> &arr){
    int n = arr.size();
    std::vector<std::vector<ll>> dp(n, std::vector<ll>(n, 0));
    // base case: len = 1 => all zeros; len = 2 => all zeros

    for(int len = 3; len <= n; len++){
        for(int i=0; i <= n-len; i++){
            int j = i+len-1;
            ll res = inf;
            for(int k = i+1;k <= j-1;k++){
                res = std::min(res, dp[i][k] + dp[k][j] + (arr[i]*arr[k]*arr[j]));
            }
            dp[i][j] = res;
        }
    }
    return dp[0][n-1];
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    std::cin>>n;
    std::vector<int> v(n);
    for(int i=0;i<n;i++){
        std::cin>>v[i];
    }
    // dp.resize(n+1, std::vector<ll>(n+1, -1));
    // std::cout<<minCost(0, n-1, v)<<"\n";
    std::cout<<minCost(v)<<"\n";

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}
=======
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
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

// std::vector<std::vector<ll>> dp;
// ll minCost(int i, int j, std::vector<int> &arr){
//     if(j-i+1 == 2) return 0;
//
//     if(dp[i][j] != -1) return dp[i][j];
//
//     int n = arr.size();
//     ll res = inf;
//     for(int k=i+1;k<j;k++){
//         res = std::min(res, minCost(i, k, arr) + minCost(k, j, arr) + (arr[i]*arr[k]*arr[j]));
//     }
//     return dp[i][j] = res;
// }

ll minCost(std::vector<int> &arr){
    int n = arr.size();
    std::vector<std::vector<ll>> dp(n, std::vector<ll>(n, 0));
    // base case: len = 1 => all zeros; len = 2 => all zeros

    for(int len = 3; len <= n; len++){
        for(int i=0; i <= n-len; i++){
            int j = i+len-1;
            ll res = inf;
            for(int k = i+1;k <= j-1;k++){
                res = std::min(res, dp[i][k] + dp[k][j] + (arr[i]*arr[k]*arr[j]));
            }
            dp[i][j] = res;
        }
    }
    return dp[0][n-1];
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    std::cin>>n;
    std::vector<int> v(n);
    for(int i=0;i<n;i++){
        std::cin>>v[i];
    }
    // dp.resize(n+1, std::vector<ll>(n+1, -1));
    // std::cout<<minCost(0, n-1, v)<<"\n";
    std::cout<<minCost(v)<<"\n";

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
