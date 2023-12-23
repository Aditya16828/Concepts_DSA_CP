<<<<<<< HEAD
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

vec<std::list<ll>> g, gt;

void dfs(int src, std::stack<ll>& st, std::set<ll>& vis) {
    vis.insert(src);
    iter_all(n, g[src]) {
        if (vis.count(n) == 0) {
            dfs(n, st, vis);
        }
    }
    st.push(src);
}

void dfs2(int src, std::set<ll>& vis, std::set<ll>& scc) {
    vis.insert(src);
    scc.insert(src);
    iter_all(n, gt[src]) {
        if (vis.count(n) == 0) {
            dfs2(n, vis, scc);
        }
    }
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int vertices, edges;
    std::cin >> vertices >> edges;
    g.resize(vertices, std::list<ll>());
    gt.resize(vertices, std::list<ll>());

    while (edges--) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        gt[v].push_back(u);
    }

    std::set<ll> vis;
    std::stack<ll> st;

    // for normal g
    for (int i = 0;i < vertices;i++) {
        if (vis.count(i) == 0) {
            dfs(i, st, vis);
        }
    }

    vis.clear();

    vec<std::set<ll>> res;
    while (st.size()) {
        int t = st.top();
        st.pop();
        std::set<ll> out;
        if (vis.count(t) == 0) {
            dfs2(t, vis, out);
        }
        if (out.empty()) continue;
        res.push_back(out);
    }

    iter_all(i, res) {
        iter_all(j, i) { std::cout << j << ", "; }
        std::cout << "\n";
    }

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

vec<std::list<ll>> g, gt;

void dfs(int src, std::stack<ll>& st, std::set<ll>& vis) {
    vis.insert(src);
    iter_all(n, g[src]) {
        if (vis.count(n) == 0) {
            dfs(n, st, vis);
        }
    }
    st.push(src);
}

void dfs2(int src, std::set<ll>& vis, std::set<ll>& scc) {
    vis.insert(src);
    scc.insert(src);
    iter_all(n, gt[src]) {
        if (vis.count(n) == 0) {
            dfs2(n, vis, scc);
        }
    }
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int vertices, edges;
    std::cin >> vertices >> edges;
    g.resize(vertices, std::list<ll>());
    gt.resize(vertices, std::list<ll>());

    while (edges--) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        gt[v].push_back(u);
    }

    std::set<ll> vis;
    std::stack<ll> st;

    // for normal g
    for (int i = 0;i < vertices;i++) {
        if (vis.count(i) == 0) {
            dfs(i, st, vis);
        }
    }

    vis.clear();

    vec<std::set<ll>> res;
    while (st.size()) {
        int t = st.top();
        st.pop();
        std::set<ll> out;
        if (vis.count(t) == 0) {
            dfs2(t, vis, out);
        }
        if (out.empty()) continue;
        res.push_back(out);
    }

    iter_all(i, res) {
        iter_all(j, i) { std::cout << j << ", "; }
        std::cout << "\n";
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
