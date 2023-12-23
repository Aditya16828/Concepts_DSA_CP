// https://www.spoj.com/problems/GSS1/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long ll)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(ll z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define vll std::vector<long long int>
#define vi std::vector<ll>
#define vb std::vector<bool>
#define pii std::pair<int, int>
#define pllll std::pair<long long int, long long int>
#define loop(i, a, b) for(ll i=a;i<=b;i++)
#define rloop(i, a, b) for(ll i=a;i>=b;i--)
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

struct node{
    ll sum;
    ll prefixSum;
    ll suffixSum;
    ll maxSum;
};

void buildTree(std::vector<ll> &arr, std::vector<node> &tree, ll start, ll end, ll tidx){
    if(start == end){
        tree[tidx].sum = arr[start];
        tree[tidx].prefixSum = arr[start];
        tree[tidx].suffixSum = arr[start];
        tree[tidx].maxSum = arr[start];
        return;
    }

    ll mid = start + (end-start)/2;
    buildTree(arr, tree, start, mid, 2*tidx+1);
    buildTree(arr, tree, mid+1, end, 2*tidx+2);
    tree[tidx].sum = tree[2*tidx+1].sum + tree[2*tidx+2].sum;
    tree[tidx].prefixSum = std::max(tree[2*tidx+1].prefixSum, tree[2*tidx+1].sum + tree[2*tidx+2].prefixSum);
    tree[tidx].suffixSum = std::max(tree[2*tidx+2].suffixSum, tree[2*tidx+2].sum + tree[2*tidx+1].suffixSum);
    tree[tidx].maxSum = std::max({tree[tidx].prefixSum, tree[tidx].suffixSum, tree[2*tidx+1].maxSum, tree[2*tidx+2].maxSum, tree[2*tidx+1].suffixSum + tree[2*tidx+2].prefixSum});
}

node query(std::vector<ll> &arr, std::vector<node> &tree, ll start, ll end, ll x, ll y, ll tidx){
    node ans;
    ans.sum = ans.prefixSum = ans.suffixSum = ans.maxSum = INT_MIN;
    if(end < x or start > y){
        return ans;
    }
    if(start >= x and end <= y){
        return tree[tidx];
    }

    ll mid = start + (end-start)/2;
    node ans1 = query(arr, tree, start, mid, x, y, 2*tidx+1);
    node ans2 = query(arr, tree, mid+1, end, x, y, 2*tidx+2);
    ans.sum = ans1.sum + ans2.sum;
    ans.prefixSum = std::max(ans1.prefixSum, ans1.sum + ans2.prefixSum);
    ans.suffixSum = std::max(ans2.suffixSum, ans2.sum + ans1.suffixSum);
    ans.maxSum = std::max({ans.prefixSum, ans.suffixSum, ans1.maxSum, ans2.maxSum, ans1.suffixSum + ans2.prefixSum});
    return ans;
}

int main(ll argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    ll n;
    std::cin>>n;
    std::vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        std::cin>>arr[i];
    }
    std::vector<node> tree(4*n);
    buildTree(arr, tree, 0, n-1, 0);
    ll m;
    std::cin>>m;
    while(m--){
        ll x, y;
        std::cin>>x>>y;
        x--, y--;
        std::cout<<query(arr, tree, 0, n-1, x, y, 0).maxSum<<"\n";
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}