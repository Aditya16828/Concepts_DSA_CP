<<<<<<< HEAD
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

#define ll long long int
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();
        ll ans = 0;
        if(n <= 2) return 0;
        std::vector<std::unordered_map<ll, ll>> dp(n);
        ll diff = (ll)((ll)arr[1] - (ll)arr[0]);
        dp[1][diff] = 1;
        for(int i=2;i<n;i++){
            for(int j=i-1;j>=0;j--){
                diff = (ll)((ll)arr[i] - (ll)arr[j]);
                if(dp[j].count(diff)){
                    dp[i][diff] += (dp[j][diff] + 1);
                    ans += dp[j][diff];

                } else {
                    dp[i][diff] += 1;
                }
            }
        }
        // for(auto &v:dp){
        //     for(auto &el:v){
        //         ans += (el.second-1);
        //     }
        // }
        return (int)ans;
    }
};

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
#define log(args...)     { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)    for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

void err(std::istream_iterator<std::string> it) {}
template<typename T, typename... Args>
void err(std::istream_iterator<std::string> it, T a, Args... args) {
    std::cout << *it << " = " << a << std::endl;
    err(++it, args...);
}

#define ll long long int
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n = arr.size();
        ll ans = 0;
        if(n <= 2) return 0;
        std::vector<std::unordered_map<ll, ll>> dp(n);
        ll diff = (ll)((ll)arr[1] - (ll)arr[0]);
        dp[1][diff] = 1;
        for(int i=2;i<n;i++){
            for(int j=i-1;j>=0;j--){
                diff = (ll)((ll)arr[i] - (ll)arr[j]);
                if(dp[j].count(diff)){
                    dp[i][diff] += (dp[j][diff] + 1);
                    ans += dp[j][diff];

                } else {
                    dp[i][diff] += 1;
                }
            }
        }
        // for(auto &v:dp){
        //     for(auto &el:v){
        //         ans += (el.second-1);
        //     }
        // }
        return (int)ans;
    }
};

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



    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
