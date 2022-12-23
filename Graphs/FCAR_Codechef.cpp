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

std::vector<std::list<int>> g;

struct comparator {
    bool operator()(pllll const& a, pllll const& b) {
        if (a.second > b.second)
            return true;
        else if(a.first < b.first)
            return true;
        return false;
    }
};

// ll bfs(int src, int dest, vll& cost, int n) {
//     std::priority_queue<pllll, std::vector<pllll>, comparator> pq;

//     pq.push({ src, cost[src] });

//     std::vector<ll> minCost(n, INT_MAX);
//     minCost[src] = cost[src];

//     ll ans = cost[src];

//     while (not pq.empty()) {
//         pllll curr = pq.top();
//         pq.pop();
//         std::cout << "{" << curr.first << ", " << curr.second << "}, ";

//         if (curr.first == dest) break;

//         for (auto& ne : g[curr.first]) {
//             ans += curr.second;
//             pq.push(ne);
//         }
//     }
//     // logarr(minCost, 0, n - 1);
//     std::cout<<"\n";
//     return ans;
// }

void bfs_up(int src, int dest){
    
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n, r;
    std::cin >> n >> r;
    vll h(n, 0), c(n, 0);
    for (int i = 0;i < n;i++) std::cin >> h[i];
    for (int i = 0;i < n;i++) std::cin >> c[i];

    // g.resize(2 * n, std::list<pllll>());
    g.resize(n, std::list<int>());

    /*
    up -> 0 to n
    down -> n to 2n
    */
    // loop(_, 0, r - 1) {
    //     int u, v;
    //     std::cin >> u >> v;
    //     u--, v--;
    //     if (h[u] <= h[v]) {
    //         g[u].push_back({ v, 0 });
    //         // g[2*v].push_back(2*u);
    //     } else if (h[u] >= h[v]) {
    //         g[u + n].push_back({ v + n,0 });
    //         // g[v].push_back(u);
    //     }
    // }
    // loop(i, 0, n - 1) {
    //     g[i].push_back({ i + n, c[i] });
    // }

    while(r--){
        int u, v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    // loop(i, 0, 2 * n - 1) {
    //     std::cout << i << "->";
    //     for (auto& el : g[i])
    //         std::cout << "{" << el.first << ", " << el.second << "}, ";
    //     std::cout << "\n";
    // }
    // std::cout << "\n\n";

    ll res = bfs(0, n - 1, c, n);
    if (res == INT_MAX) {
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