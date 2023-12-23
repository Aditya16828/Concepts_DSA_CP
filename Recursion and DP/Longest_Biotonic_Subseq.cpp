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

std::vector<ll> forward_lis(std::vector<ll> &arr){
    int n = arr.size();
    std::vector<ll> dp(n, 0);
    dp[0] = 1;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j] < arr[i]){
                dp[i] = std::max(dp[i], dp[j]+1);
            }
        }
    }
    return dp;
}

std::vector<ll> backward_lis(std::vector<ll> &arr){
    int n = arr.size();
    std::vector<ll> dp(n, 0);
    dp[n-1] = 1;
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[j] < arr[i]){
                dp[i] = std::max(dp[i], dp[j]+1);
            }
        }
    }
    return dp;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    std::cin>>n;
    std::vector<ll> arr(n);
    for(int i=0;i<n;i++) std::cin>>arr[i];
    std::vector<ll> f_lis = forward_lis(arr);
    std::vector<ll> b_lis = backward_lis(arr);
    logarr(f_lis, 0, f_lis.size()-1);
    logarr(b_lis, 0, b_lis.size()-1);
    std::vector<ll> res(n);
    for(int i=0;i<n;i++){
        res[i] = f_lis[i] + b_lis[i] - 1;
    }
    logarr(res, 0, res.size()-1);
    int ans = *std::max_element(res.begin(), res.end());
    log(ans);
    std::cout<<"\n";


    #ifndef ONLINE_JUDGE
      clock_t end = clock();
      std::cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}
