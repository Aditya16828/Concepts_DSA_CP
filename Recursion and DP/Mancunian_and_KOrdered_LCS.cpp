<<<<<<< HEAD
// https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
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

int dp[2001][2001][6];
int lcs(int i, int j, int k, std::vector<ll> &v1, std::vector<ll> &v2) {
    if (i == -1 or j == -1) {
        return 0;
    }
    if (dp[i][j][k] != -1) return dp[i][j][k];
    if (v1[i] == v2[j]) {
        int case1 = lcs(i - 1, j - 1, k, v1, v2) + 1;
        return dp[i][j][k] = case1;
    }
    int case2 = 0, case3 = 0;
    if (k > 0) {
        case2 = lcs(i - 1, j - 1, k - 1, v1, v2) + 1;
        case3 = std::max(lcs(i - 1, j, k, v1, v2), lcs(i, j - 1, k, v1, v2));
        return dp[i][j][k] = std::max(case3, case2);
    }
    case3 = std::max(lcs(i - 1, j, k, v1, v2), lcs(i, j - 1, k, v1, v2));
    return dp[i][j][k] = case3;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<ll> v1(n), v2(m);
    for (int i = 0; i < n; i++) std::cin >> v1[i];
    for (int i = 0; i < m; i++) std::cin >> v2[i];

    std::memset(dp, -1, sizeof dp);
    std::cout << lcs(n - 1, m - 1, k, v1, v2) << "\n";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
=======
// https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/
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

int dp[2001][2001][6];
int lcs(int i, int j, int k, std::vector<ll> &v1, std::vector<ll> &v2) {
    if (i == -1 or j == -1) {
        return 0;
    }
    if (dp[i][j][k] != -1) return dp[i][j][k];
    if (v1[i] == v2[j]) {
        int case1 = lcs(i - 1, j - 1, k, v1, v2) + 1;
        return dp[i][j][k] = case1;
    }
    int case2 = 0, case3 = 0;
    if (k > 0) {
        case2 = lcs(i - 1, j - 1, k - 1, v1, v2) + 1;
        case3 = std::max(lcs(i - 1, j, k, v1, v2), lcs(i, j - 1, k, v1, v2));
        return dp[i][j][k] = std::max(case3, case2);
    }
    case3 = std::max(lcs(i - 1, j, k, v1, v2), lcs(i, j - 1, k, v1, v2));
    return dp[i][j][k] = case3;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<ll> v1(n), v2(m);
    for (int i = 0; i < n; i++) std::cin >> v1[i];
    for (int i = 0; i < m; i++) std::cin >> v2[i];

    std::memset(dp, -1, sizeof dp);
    std::cout << lcs(n - 1, m - 1, k, v1, v2) << "\n";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
