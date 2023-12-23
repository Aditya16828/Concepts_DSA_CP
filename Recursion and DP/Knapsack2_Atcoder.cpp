<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

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

    ll n, W;
    std::cin >> n >> W;
    std::vector<ll> w(n), v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i] >> v[i];
    }
    std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(100005, 1e10));
    // dp[i][j] -> min weight reqd to obtain j amt of profit using i items.
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[1][v[0]] = w[0];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 100005; j++) {
            dp[i][j] = dp[i - 1][j]; // not pick
            if (v[i - 1] <= j) {
                dp[i][j] = std::min(dp[i][j], w[i - 1] + dp[i - 1][j - v[i - 1]]);
            }
        }
    }

    ll res = 0;
    for (int j = 0; j < 100005; j++) {
        if (dp[n][j] <= W) res = j;
    }
    std::cout << res << '\n';

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
=======
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

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

    ll n, W;
    std::cin >> n >> W;
    std::vector<ll> w(n), v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> w[i] >> v[i];
    }
    std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(100005, 1e10));
    // dp[i][j] -> min weight reqd to obtain j amt of profit using i items.
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[1][v[0]] = w[0];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 100005; j++) {
            dp[i][j] = dp[i - 1][j]; // not pick
            if (v[i - 1] <= j) {
                dp[i][j] = std::min(dp[i][j], w[i - 1] + dp[i - 1][j - v[i - 1]]);
            }
        }
    }

    ll res = 0;
    for (int j = 0; j < 100005; j++) {
        if (dp[n][j] <= W) res = j;
    }
    std::cout << res << '\n';

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
