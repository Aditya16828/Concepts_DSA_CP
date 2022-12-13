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

std::vector<std::list<pii>> graph;

std::vector<int> bfs(int src){
    std::vector<int> sd(graph.size(), INT_MAX);
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> q;

    sd[src] = 0;

    for(int i = 0;i < sd.size(); i++){
        q.push({sd[i], i});
    }

    std::vector<bool> vis(graph.size(), false);

    while(not q.empty()){
        pii curr = q.top();
        q.pop();
        if(vis[curr.second])
            continue;
        vis[curr.second] = true;
        for(auto &ne:graph[curr.second]){
            int ne_node = ne.first;
            int wt = ne.second;
            if(sd[ne_node] > sd[curr.second] + wt){
                sd[ne_node] = sd[curr.second] + wt;
                q.push({sd[ne_node], ne_node});
            }
        }
    }

    return sd;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int vertices, edges;
    std::cin>>vertices>>edges;
    graph.resize(vertices, std::list<pii>());

    int e = edges;
    while(e--){
        int u, v, wt;
        std::cin>>u>>v>>wt;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }

    std::vector<int> temp = bfs(0); // src -> 0
    for(int i=0;i<temp.size();i++){
        std::cout<<"{"<<i<<", "<<temp[i]<<"}, ";
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}