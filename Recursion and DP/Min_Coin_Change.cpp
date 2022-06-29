// Coin change problem Leetcode
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

std::vector<ll> dp;
ll helper(std::vector<int>& coins, ll amt){
    if(amt == 0) return 0;
    if(amt < 0) return INT64_MAX;
    if(dp[amt] != -1) return dp[amt];
    ll n = coins.size(), ans = INT64_MAX;
    for(int i=0;i<n;i++){
        ans = std::min(ans, helper(coins, amt-coins[i]));
    }
    return dp[amt] = (ans == INT64_MAX) ? INT64_MAX : (1+ans);
}

int coinChange(std::vector<int>& coins, ll amount){
    dp.resize(amount+2, -1);
    ll x = helper(coins, amount);
    return (x == INT_MAX) ? -1 : x;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n, x;
    std::cin>>n>>x;
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) std::cin>>c[i];
    std::cout<<coinChange(c, x)<<"\n";    

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
