// https://www.spoj.com/problems/MIXTURES/
#include <bits/stdc++.h>
#define ll long long int
#define mod 100
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

void prefixSum(std::vector<ll> &arr){
    int n = arr.size();
    for(int i=1;i<n;i++){
        arr[i] = (arr[i-1] + arr[i]);
    }
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    while(std::cin>>n){
        std::vector<ll> arr(n);
        for(int i=0;i<n;i++) std::cin>>arr[i];

        std::vector<ll> prefix(arr);
        prefixSum(prefix);

        std::vector<std::vector<ll>> dp(n, std::vector<ll>(n, 0));
        // for(int i=0;i<n-1;i++){
        //     dp[i][i+1] = (arr[i]*arr[i+1]);
        // }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         std::cout<<dp[i][j]<<", ";
        //     }
        //     std::cout<<"\n";
        // }
        for(int len = 2;len <= n;len++){
            for(int i=0;i<=n-len;i++){
                int j = i + len-1;
                ll res = inf;
                for(int k=i;k <= j-1;k++){
                    ll x = ((prefix[k] - prefix[i] + arr[i])%mod) * ((prefix[j]-prefix[k])%mod);
                    res = std::min(res, dp[i][k] + dp[k+1][j] + x);
                    // std::cout<<res<<"; ";
                }
                dp[i][j] = res;
            }
        }
        // std::cout<<"\n";
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         std::cout<<dp[i][j]<<", ";
        //     }
        //     std::cout<<"\n";
        // }
        std::cout<<dp[0][n-1]<<"\n";
    }

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}
