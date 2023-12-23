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

ll Get(vi& parent, int a) {
    if (parent[a] == a) {
        return a;
    } else {
        return parent[a] = Get(parent, parent[a]);
    }
}

ll Union(vi& parent, vi& rank, int a, int b) {
    a = Get(parent, a);
    b = Get(parent, b);

    if (rank[a] == rank[b]) {
        rank[a]++;
    }
    if (rank[a] > rank[b]) {
        parent[b] = a;
    } else {
        parent[a] = b;
    }
}

class Edge {
public:
    int src, dest, wt;
};

bool cmp(Edge& e1, Edge& e2) {
    return (e1.wt < e2.wt);
}

std::vector<Edge> kruskals(std::vector<Edge>& edges, int n) {
    std::vector<Edge> ans;
    std::vector<int> parent(n), rank(n, 1);

    loop(i, 0, n - 1) {
        parent[i] = i;
    }

    std::sort(edges.begin(), edges.end(), cmp);

    for (int i = 0;i < edges.size() and ans.size() < n;i++) {
        int psrc = Get(parent, edges[i].src);
        int pdest = Get(parent, edges[i].dest);

        if (psrc != pdest) {
            ans.emplace_back(edges[i]);
            Union(parent, rank, psrc, pdest);
        }
    }
    return ans;
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....



#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}