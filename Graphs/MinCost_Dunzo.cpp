/*
Question:
    Given a matrix of characters, the character on each cell represents the direction in which u can travel inorder to go to the next cell. Src = top left corner, destination = bottom right corner. Now it may happen that u may or may not reach the destination. In order to reach the destination u perform certain modifications, each modification cost 1. U need find the min modifications in order to reach the destination.
*/
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

vec<std::list<pii>> g;

int index(int i, int j, int m, int n, char dir){
    if(dir == 'U') i--;
    if(dir == 'D') i++;
    if(dir == 'L') j--;
    if(dir == 'R') j++;
    return (i*n+j);
}

void disp_g(){
    for(int i=0;i<g.size();i++){
        std::cout<<i<<"-> ";
        for(auto &el:g[i]){
            std::cout<<"{"<<el.first<<", "<<el.second<<"}, ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

int bfs(int m, int n){
    int src = 0, dest = g.size()-1;
    std::deque<int> q;
    q.push_front(src);

    vi cost(g.size(), INT_MAX);
    cost[src] = 0;
    
    while(not q.empty()){
        int curr = q.front();
        q.pop_front();
        for(auto &ne:g[curr]){
            if(cost[ne.first] > cost[curr] + ne.second){
                cost[ne.first] = cost[curr] + ne.second;

                if(ne.second == 1) q.push_back(ne.first);
                else q.push_front(ne.first);
            }
        }

    }
    return cost[dest];
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int m, n;
    std::cin>>m>>n;
    std::vector<std::vector<char>> mat(m, std::vector<char>(n, ' '));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            std::cin>>mat[i][j];
        }
    }

    g.resize(m*n, std::list<pii>());

    char dir[] = {'U', 'D', 'L', 'R'};
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int idx = i*n+j;
            for(int d=0;d<=3;d++){
                int to_idx = index(i, j, m, n, dir[d]);
                if(to_idx < 0 or to_idx > ((m-1)*n+(n-1))) continue;

                if(mat[i][j] == dir[d]){
                    g[idx].push_back({to_idx, 0});
                } else {
                    g[idx].push_back({to_idx, 1});
                }
            }
        }
    }

    disp_g();
    std::cout<<bfs(m, n)<<"\n";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}