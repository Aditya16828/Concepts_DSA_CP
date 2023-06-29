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

std::vector<int> low((int)(1e5)+2);
std::vector<int> disctime((int)(1e5)+2, -1);
int dtime = 1;

std::vector<int> art_pt;
std::vector<pii> bridges;

void dfs(int src, int parent = -1){
    low[src] = disctime[src] = dtime;
    dtime++;

    int children = 0;
    for(auto &ne:g[src]){
        if(ne == parent)
            continue;
        if(disctime[ne] == -1){ // not visited
            dfs(ne, src);
            low[src] = std::min(low[src], low[ne]);

            if(parent!=-1 and low[ne]>=disctime[src]){
                art_pt.push_back(src);
            }

            if(low[ne] > disctime[src]){
                bridges.push_back({src, ne});
            }
            ++children;
        } else {
            low[src] = std::min(low[src], disctime[ne]);
        }
    }

    if(parent==-1 and children>=2){
        art_pt.push_back(src);
    }
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int vertices, edges;
    std::cin>>vertices>>edges;

    g.resize(vertices, std::list<int>());

    while(edges--){
        int u, v;
        std::cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    std::cout<<"Articulation points are:\n";
    logarr(art_pt, 0, art_pt.size()-1);
    std::cout<<"\nBridges are:\n";
    loop(i, 0, bridges.size()-1){
        std::cout<<bridges[i].first<<"-"<<bridges[i].second<<"\n";
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}