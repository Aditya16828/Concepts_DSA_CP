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

std::vector<std::list<std::pair<int, int>>> g;

class Edge {
public:
    int u, v;
    int wt;
    Edge(int u, int v, int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class triplet {
public:
    std::vector<int> v1;
    std::vector<int> v2;
    bool b;
    triplet(std::vector<int> v1, std::vector<int> v2, bool b) {
        this->v1 = v1;
        this->v2 = v2;
        this->b = b;
    }
};

triplet bellmanford(int src, int vertices) {
    std::vector<int> sd(vertices, INT_MAX);
    std::vector<int> parent(vertices, -1);

    sd[src] = 0;

    std::vector<Edge> edges;

    for(auto &ne:g[src]){
        Edge e = Edge(src, ne.first, ne.second);
        edges.emplace_back(e);
    }

    for(int i=0;i<vertices;i++){
        if(i == src) continue;
        for(auto &ne:g[i]){
            Edge e = Edge(i, ne.first, ne.second);
            edges.emplace_back(e);
        }
    }
    // for(int i=0;i<edges.size();i++){
    //     std::cout<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].wt;
    //     std::cout<<"\n";
    // }

    for (int i = 1;i <= vertices - 1;i++) {
        for(auto &edge:edges){
            if(sd[edge.v] > sd[edge.u] + edge.wt){
                sd[edge.v] = sd[edge.u] + edge.wt;
                parent[edge.v] = edge.u;
            }
        }
    }

    // logarr(parent, 0, parent.size()-1);
    // logarr(sd, 0, sd.size()-1);

    for(int i=0;i<edges.size();i++){
        if(sd[edges[i].v] > sd[edges[i].u] + edges[i].wt){
            return triplet({}, {}, false);
        }
    }

    return triplet(sd, parent, true);
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int vertices, edges;
    std::cin >> vertices >> edges;

    g.resize(vertices, std::list<std::pair<int, int>>());

    while (edges--) {
        int u, v;
        int wt;
        std::cin >> u >> v >> wt;
        g[u].push_back({ v, wt });
        // g[v].push_back({ u, wt });
    }

    triplet temp = bellmanford(0, vertices);
    if(temp.b){
        std::cout<<"shortest Distance Array:\n";
        logarr(temp.v1, 0, temp.v1.size()-1);

        std::cout<<"\nParent array:\n";
        for(int i=0;i<temp.v2.size();i++){
            if(temp.v2[i] == -1) continue;
            std::cout<<temp.v2[i]<<" -> "<<i<<"\n";
        }
    } else {
        std::cout<<"Cycle Detected";
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}