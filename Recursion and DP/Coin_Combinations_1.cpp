// https://cses.fi/problemset/task/1635
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

ll total_permutations(std::vector<int> &coins, int amt){
    int n = coins.size();
    std::vector<ll> dp(amt+2, 0);
    dp[0] = 1;
    for(ll i=1;i<=amt;i++){
        for(ll j=0;j<n;j++){
            if(i - coins[j] < 0) continue;
            dp[i] = ((dp[i] + dp[i-coins[j]])%mod);
        }
    }
    return dp[amt];
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n, x;
    std::cin>>n>>x;
    std::vector<int> c(n);
    for(int i=0;i<n;i++) std::cin>>c[i];
    std::cout<<total_permutations(c, x)<<"\n";

    #ifndef ONLINE_JUDGE 
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif 
    return 0;
}
