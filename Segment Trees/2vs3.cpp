// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/2-vs-3/
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

struct node{
    ll len;
    ll val;
};

ll modExp(ll base, ll exp, ll m){
    ll ans = 1;
    base %= m;
    while(exp){
        if(exp%2 != 0){
            ans = ((ans%m)*(base%m))%m;
        }
        base = ((base%m)*(base%m))%m;
        exp>>=1;
    }

    return ans;
}

void buildTree(std::vector<char> &arr, std::vector<node> &tree, ll start, ll end, ll tidx){
    if(start == end){
        tree[tidx].len = 1;
        tree[tidx].val = arr[start]-'0';
        return;
    }

    int mid = start + (end-start)/2;
    buildTree(arr, tree, start, mid, 2*tidx+1);
    buildTree(arr, tree, mid+1, end, 2*tidx+2);
    tree[tidx].len = tree[2*tidx+1].len + tree[2*tidx+2].len;
    tree[tidx].val = (tree[2*tidx+1].val%3*modExp(2, tree[2*tidx+2].len, 3) + tree[2*tidx+2].val%3)%3;
}

node query(std::vector<char> &arr, std::vector<node> &tree, ll start, ll end, ll l, ll r, ll tidx){
    node ans;
    ans.len = 0;
    ans.val = 0;
    if(end < l or start > r){
        return ans;
    }
    if(start >= l and end <= r){
        return tree[tidx];
    }

    int mid = start+(end-start)/2;
    node ans_left = query(arr, tree, start, mid, l, r, 2*tidx+1);
    node ans_right = query(arr, tree, mid+1, end, l, r, 2*tidx+2);
    ans.len = ans_left.len + ans_right.len;
    ans.val = (ans_left.val%3*modExp(2, ans_right.len, 3) + ans_right.val)%3;
    return ans;
}

void update(std::vector<char> &arr, std::vector<node> &tree, ll idx, ll start, ll end, ll tidx){
    if(start == end){
        if(arr[idx] == '0'){
            arr[idx] = '1';
            tree[tidx].val = 1;
        }
        return;
    }

    int mid = start + (end-start)/2;
    if(idx <= mid) update(arr, tree, idx, start, mid, 2*tidx+1);
    else update(arr, tree, idx, mid+1, end, 2*tidx+2);
    tree[tidx].len = tree[2*tidx+1].len + tree[2*tidx+2].len;
    tree[tidx].val = (tree[2*tidx+1].val%3*modExp(2, tree[2*tidx+2].len, 3) + tree[2*tidx+2].val%3)%3;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int n;
    std::cin>>n;
    std::string s;
    std::cin>>s;
    std::vector<char> arr(s.begin(), s.end());
    std::vector<node> tree(4*n);
    buildTree(arr, tree, 0, n-1, 0);
    int q;
    std::cin>>q;
    while(q--){
        int type;
        std::cin>>type;
        if(type == 0){
            int l, r;
            std::cin>>l>>r;
            std::cout<<query(arr, tree, 0, n-1, l, r, 0).val<<"\n";
        } else {
            int idx;
            std::cin>>idx;
            update(arr, tree, idx, 0, n-1, 0);
        }
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}