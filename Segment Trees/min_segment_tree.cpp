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

std::vector<int> arr, tree;

int query(int l, int r, int nl, int nr, int tidx){
    if(r < nl or nr < l){
        return INT_MAX;
    }
    if(l <= nl and r >= nr){
        return tree[tidx];
    }

    int mid = nl + (nr-nl)/2;
    int ans1 = query(l, r, nl, mid, 2*tidx+1);
    int ans2 = query(l, r, mid+1, nr, 2*tidx+2);
    return std::min(ans1, ans2);
}

void update(int idx, int val, int nl, int nr, int tidx){
    if(nl == nr){
        tree[tidx] = val;
        arr[idx] = val;
        return;
    }

    int mid = nl + (nr-nl)/2;
    if(idx <= mid){
        update(idx, val, nl, mid, 2*tidx+1);
    } else {
        update(idx, val, mid+1, nr, 2*tidx+2);
    }

    tree[tidx] = std::min(tree[2*tidx+1], tree[2*tidx+2]);
}

void buildTree(int nl, int nr, int tidx){
    if(nl == nr){
        tree[tidx] = arr[nl];
        return;
    }

    int mid = nl + (nr - nl)/2;
    buildTree(nl, mid, 2*tidx+1);
    buildTree(mid+1, nr, 2*tidx+2);
    tree[tidx] = std::min(tree[2*tidx+1], tree[2*tidx+2]);
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    std::cin>>n;
    arr.resize(n, 0);
    tree.resize(4*n, 0);
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }

    buildTree(0, n-1, 0);

    int q;
    std::cin>>q;
    while(q--){
        int type;
        std::cin>>type;
        // 0 -> update
        // 1 -> query
        if(type == 0){
            int idx, val;
            std::cin>>idx>>val;
            update(idx, val, 0, n-1, 0);
        } else {
            int l, r;
            std::cin>>l>>r;
            int ans = query(l, r, 0, n-1, 0);
            std::cout<<ans<<"\n";
        }
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}