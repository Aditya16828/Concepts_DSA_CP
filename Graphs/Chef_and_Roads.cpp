#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define vll std::vector<long long int>
#define vi std::vector<int>
#define vb std::vector<bool>
#define pii std::pair<int, int>
#define pllll std::pair<long long int, long long int>
#define loop(i, a, b) for(int i=a;i<=b;i++)
#define rloop(i, a, b) for(int i=a;i>=b;i--)
#define iter_all(el, cont) for(auto &el:cont)

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

std::vector<std::list<int>> g;

vi dp;

int ways(int src, int dest, vb& vis) {
    if (src == dest) return 1;
    if (dp[src] != -1) return dp[src];
    vis[src] = true;
    int ans = 0;
    iter_all(ne, g[src]) {
        if (not vis[ne]) {
            ans = ans % mod + ways(ne, dest, vis);
            ans %= mod;
        }
    }
    vis[src] = false;
    return dp[src] = ans;
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n, m;
    std::cin >> n >> m;
    g.resize(n + 1, std::list<int>());
    int p, q;
    std::cin >> p >> q;
    loop(i, 1, m) {
        int a, b;
        std::cin >> a >> b;
        g[a].push_back(b);
    }
    vb vis(n + 1, 0);
    dp.resize(n + 1, -1);
    std::cout << ways(p, q, vis) << "\n";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
