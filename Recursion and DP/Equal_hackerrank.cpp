// https://www.hackerrank.com/challenges/equal/problem
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

void set_dp(std::vector<ll>& dp) {
    dp[0] = 0;
    // for 1
    for (int i = 1;i < dp.size();i++) {
        if (i - 1 < 0) continue;
        dp[i] = std::min(dp[i], dp[i - 1] + 1);
    }
    // for 2
    for (int i = 1;i < dp.size();i++) {
        if (i - 2 < 0) continue;
        dp[i] = std::min(dp[i], dp[i - 2] + 1);
    }
    // for 5
    for (int i = 1;i < dp.size();i++) {
        if (i - 5 < 0) continue;
        dp[i] = std::min(dp[i], dp[i - 5] + 1);
    }
}

ll min_ops_equal(std::vector<ll>& v) {
    int n = v.size();
    ll max_ele = *(std::max_element(v.begin(), v.end()));
    ll min_ele = *(std::min_element(v.begin(), v.end()));
    std::vector<ll> dp(max_ele + 50, INT_MAX); // minimum steps required to reduce ith number to zero using 1, 2 and 5
    set_dp(dp);
    ll ans = INT64_MAX;
    for (ll i = -10;i <= min_ele;i++) {
        ll sum = 0;
        for (ll j = 0;j < n;j++) {
            sum += dp[v[j] - i];
        }
        ans = std::min(sum, ans);
    }
    return ans;
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<ll> arr(n);
        for (int i = 0;i < n;i++) std::cin >> arr[i];
        std::cout << min_ops_equal(arr) << "\n";
    }

#ifndef ONLINE_JUDGE 
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif 
    return 0;
}
