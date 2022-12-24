// https://www.codechef.com/problems-old/INSQ15_F
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define vec std::vector
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

std::vector<std::list<pllll>> g;

ll bfs(ll src, ll dest, ll n) {
    std::priority_queue<pllll, std::vector<pllll>, std::greater<pllll>> pq;

    pq.push({ 0, src });

    std::vector<ll> minCost(n, inf);
    minCost[src] = 0;

    std::vector<bool> vis(2 * n + 2, false);

    while (not pq.empty()) {
        pllll curr = pq.top();
        pq.pop();
        // std::cout << "{" << curr.first << ", " << curr.second << "}, ";

        if (curr.second == dest) break;
        if (vis[curr.second]) continue;

        vis[curr.second] = true;

        for (auto& ne : g[curr.second]) {
            if (minCost[ne.first] > minCost[curr.second] + ne.second) {
                minCost[ne.first] = minCost[curr.second] + ne.second;
                pq.push({ minCost[ne.first], ne.first });
            }
        }
    }
    return minCost[dest];
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    ll n, r;
    std::cin >> n >> r;
    vll h(n+1, 0), c(n+1, 0);
    for (int i = 1;i <= n;i++) std::cin >> h[i];
    for (int i = 1;i <= n;i++) std::cin >> c[i];

    g.resize(2 * n + 2, std::list<pllll>());

    /*
    up -> 0 to n
    down -> n+1 to 2n+1
    */
    loop(_, 0, r - 1) {
        ll u, v;
        std::cin >> u >> v;
        if (h[u] <= h[v]) {
            g[u].push_back({ v, 0 });
        }
        if (h[u] >= h[v]) {
            g[u + n].push_back({ v + n,0 });
        }

        if (h[v] <= h[u]) {
            g[v].push_back({ u, 0 });
        }
        if (h[v] >= h[u]) {
            g[v + n].push_back({ u + n, 0 });
        }
    }
    loop(i, 1, n) {
        g[i].push_back({ i + n, c[i] });
        g[i + n].push_back({ i, c[i] });
    }
    g[0].push_back({1, c[1]});
    g[0].push_back({n+1, c[1]});
    g[2*n].push_back({2*n+1, 0});
    g[n].push_back({2*n+1, 0});


    ll res = bfs(0, 2 * n+1, 2 * n + 2);
    if (res == inf) {
        std::cout << "-1\n";
    } else {
        std::cout << res << "\n";
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}