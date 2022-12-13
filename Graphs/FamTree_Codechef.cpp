// https://www.codechef.com/problems/FAMTREE
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

vec<std::list<int>> g;

ll ans = INT_MIN;
pii f(int src,  vll &wt, int parent = -1){
    pllll res = {INT_MAX, INT_MIN};
    for(auto &n:g[src]){
        if(n == parent) continue;

        pllll temp = f(n, wt, src);
                
        res.first = std::min(res.first, temp.first);
        res.second = std::max(res.second, temp.second);
    }
    if(res.first != INT_MAX and res.second != INT_MIN)
        ans = std::max({ans, (ll)abs(res.first - wt[src]), (ll)abs(res.second - wt[src])});
    return {std::min(res.first, wt[src]), std::max(res.second, wt[src])};
}

void disp_g(){
    for(int i=0;i<g.size();i++){
        std::cout<<i<<"-> ";
        for(auto &el:g[i]){
            std::cout<<el<<", ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    /**Main Jist:
        Max difference between 2 members, one is parent and other is its descendant.    
    */
    int n;
    std::cin>>n;
    vll wt(n+1, 0);
    vi p(n, -1);
    for(int i=1;i<=n;i++) std::cin>>wt[i];
    for(int i=1;i<=n;i++) std::cin>>p[i];

    g.resize(n+1, std::list<int>());
    int src = -1;
    for(int i=1;i<=n;i++){
        if(p[i] == -1) {src = i; continue;}
        g[i].push_back(p[i]);
        g[p[i]].push_back(i);
    }

    // std::cout<<g.size()<<"\n";
    // disp_g();

    f(src, wt);
    std::cout<<ans<<"\n";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}