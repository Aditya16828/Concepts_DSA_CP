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

class Edge{
public:
    int src, dest, wt;
    Edge(int s, int d, int w){
        this->src = s;
        this->dest = d;
        this->wt = w;
    }
};

std::vector<std::list<pii>> g;

std::vector<Edge> prims(int root, int vertices){
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    std::vector<int> parent(vertices, -1), edgewt(vertices, INT_MAX);
    std::vector<int> visited(vertices, 0);

    edgewt[root] = 0;
    for(int i=0;i<vertices;i++){
        pq.push({edgewt[i], i});
    }

    std::vector<Edge> ans;
    while(not pq.empty()){
        pii curr = pq.top();
        pq.pop();

        if(visited[curr.second])
            continue;
        
        visited[curr.second] = true;

        for(auto &ne:g[curr.second]){
            if(ne.second < edgewt[ne.first] and !visited[ne.first]){
                edgewt[ne.first] = ne.second;
                parent[ne.first] = curr.second;
                pq.push({ne.second, ne.first});
            }
        }
    }

    for(int i=0;i<vertices;i++){
        if(parent[i] == -1)
            continue;
        // Edge e = Edge(parent[i], i, edgewt[i]);
        ans.emplace_back(Edge(parent[i], i, edgewt[i]));
    }

    return ans;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int vertices, edges;
    std::cin>>vertices>>edges;
    g.resize(vertices, std::list<pii>());
    while(edges--){
        char u, v;
        int wt;
        std::cin>>u>>v>>wt;
        g[(int)(u-'a')].push_back({(int)(v-'a'), wt});
        g[(int)(v-'a')].push_back({(int)(u-'a'), wt});
    }

    std::vector<Edge> ans = prims(0, vertices);
    for(int i=0;i<ans.size();i++){
        std::cout<<"{"<<(char)('a' + ans[i].src)<<", "<<(char)('a'+ans[i].dest)<<"} -> "<<ans[i].wt<<"\n";
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}