<<<<<<< HEAD
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

std::vector<std::list<ll>> graph;
vll bfs(ll src, ll dest, ll n) {
    std::queue<ll> q;
    q.push(src);
    vb visited(n, false);
    visited[src] = true;
    vll dist(n, 0);
    while (not q.empty()) {
        int v = q.front();
        q.pop();
        // std::cout << v << ", ";
        iter_all(ne, graph[v]) {
            if (not visited[ne]) {
                q.push(ne);
                dist[ne] += (dist[v] + 1);
                visited[ne] = true;
            }
        }
        // visited[v] = true;
    }
    return dist;
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int vertices, edges;
    std::cin >> vertices >> edges;
    graph.resize(vertices, std::list<ll>());
    while (edges--) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll src, dest;
    std::cin >> src >> dest;
    src--;
    dest--;
    vll dist_src = bfs(src, dest, vertices);
    // std::cout << "\n";
    vll dist_dest = bfs(dest, src, vertices);
    // std::cout << "\n";
    // logarr(dist_src, 0, dist_src.size() - 1);
    // logarr(dist_dest, 0, dist_dest.size() - 1);
    ll mindist = dist_src[dest];
    vll ans;
    loop(i, 0, vertices - 1) {
        if (dist_src[i] + dist_dest[i] == mindist) {
            ans.push_back(i);
        }
    }
    iter_all(el, ans) {
        std::cout << el << ", ";
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

std::vector<std::list<ll>> graph;
vll bfs(ll src, ll dest, ll n) {
    std::queue<ll> q;
    q.push(src);
    vb visited(n, false);
    visited[src] = true;
    vll dist(n, 0);
    while (not q.empty()) {
        int v = q.front();
        q.pop();
        // std::cout << v << ", ";
        iter_all(ne, graph[v]) {
            if (not visited[ne]) {
                q.push(ne);
                dist[ne] += (dist[v] + 1);
                visited[ne] = true;
            }
        }
        // visited[v] = true;
    }
    return dist;
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int vertices, edges;
    std::cin >> vertices >> edges;
    graph.resize(vertices, std::list<ll>());
    while (edges--) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    ll src, dest;
    std::cin >> src >> dest;
    src--;
    dest--;
    vll dist_src = bfs(src, dest, vertices);
    // std::cout << "\n";
    vll dist_dest = bfs(dest, src, vertices);
    // std::cout << "\n";
    // logarr(dist_src, 0, dist_src.size() - 1);
    // logarr(dist_dest, 0, dist_dest.size() - 1);
    ll mindist = dist_src[dest];
    vll ans;
    loop(i, 0, vertices - 1) {
        if (dist_src[i] + dist_dest[i] == mindist) {
            ans.push_back(i);
        }
    }
    iter_all(el, ans) {
        std::cout << el << ", ";
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
