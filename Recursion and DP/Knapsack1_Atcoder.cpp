// https://atcoder.jp/contests/dp/tasks/dp_d
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

int n;
std::vector<int> wt;
std::vector<ll> cost;
// ll dp[105][100005];

// ll maxProfit_TD(int i, LL W){
//     if(i == n) return 0;
//     if(W <= 0) return 0;
//     if(dp[i][W] != -1) return dp[i][W];
//
//     // pick
//     ll c1 = 0;
//     if(wt[i] <= W){
//         c1 = cost[i] + maxProfit(i+1, W-wt[i]);
//     }
//     // not pick
//     ll c2 = maxProfit(i+1, W);
//     ll result = std::max(c1, c2);
//
//     return dp[i][W] = result;
// }

ll maxProfit_BU(ll W){
    std::vector<std::vector<ll>> dp(n+1, std::vector<ll>(W+2, 0));
    // 2 base cases: 1. if target weight W = 0, then profit = 0
    // 2. if items = 0 then profit = 0.
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= wt[i-1]) dp[i][j] = std::max(dp[i-1][j], cost[i-1]+dp[i-1][j-wt[i-1]]);
        }
    }
    return dp[n][W];
}

ll maxProfit_BU_btr(ll W){
    std::vector<ll> dp1(W+2, 0), dp2(W+2, 0);
    for(int i=0;i<n;i++){
        for(int j=1;j<=W;j++){
            dp2[j] = dp1[j]; // not pick
            if(j >= wt[i]){ // pick
                dp2[j] = std::max(dp1[j], cost[i] + dp1[j-wt[i]]);
            }
        }
        dp1 = dp2;
        dp2.clear();
        dp2.resize(W+2, 0);
    }
    return dp1[W];
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    ll W;
    std::cin>>n>>W;
    wt.resize(n);
    cost.resize(n);
    for(int i=0;i<n;i++){
        std::cin>>wt[i]>>cost[i];
    }
    // dp.memset(dp, -1, sizeof dp);
    // std::cout<<maxProfit_TD(0, W)<<"\n";
    std::cout<<maxProfit_BU_btr(W)<<"\n";

    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}
