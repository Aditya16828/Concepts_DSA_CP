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

struct Node{
    ll sum, prefix_max, suffix_max, max_sum;
};

void build(std::vector<Node*>& seg, vll& arr, int start, int end, int tidx){
    if (start == end){
        seg[tidx]->sum = arr[start];
        seg[tidx]->prefix_max = arr[start];
        seg[tidx]->suffix_max = arr[start];
        seg[tidx]->max_sum = arr[start];
        return;
    }

    int mid = start + (end - start) / 2;

    build(seg, arr, start, mid, 2 * tidx + 1);
    build(seg, arr, mid + 1, end, 2 * tidx + 2);

    seg[tidx]->sum = seg[2 * tidx + 1]->sum + seg[2 * tidx + 2]->sum;
    seg[tidx]->suffix_max = std::max(seg[2 * tidx + 2]->suffix_max, seg[2 * tidx + 2]->sum + seg[2 * tidx + 1]->suffix_max);
    seg[tidx]->prefix_max = std::max(seg[2 * tidx + 1]->prefix_max, seg[2 * tidx + 1]->sum + seg[2 * tidx + 2]->prefix_max);
    seg[tidx]->max_sum = std::max({ seg[2 * tidx + 1]->max_sum, seg[2 * tidx + 2]->max_sum, seg[2 * tidx + 1]->suffix_max + seg[2 * tidx + 2]->prefix_max });
}

Node* query(std::vector<Node*>& seg, int start, int end, int tidx, int l, int r){
    Node* n = new Node();
    n->sum = INT_MIN; n->max_sum = INT_MIN; n->prefix_max = INT_MIN; n->suffix_max = INT_MIN;
    if (end < l or start > r){
        return n;
    }

    if (start >= l and r >= end){
        return seg[tidx];
    }

    int mid = start + (end - start) / 2;

    Node* lst = query(seg, start, mid, 2 * tidx + 1, l, r);
    Node* rst = query(seg, mid + 1, end, 2 * tidx + 2, l, r);

    n->sum = lst->sum + rst->sum;
    n->suffix_max = std::max(rst->suffix_max, rst->sum + lst->suffix_max);
    n->prefix_max = std::max(lst->prefix_max, lst->sum + rst->prefix_max);
    n->max_sum = std::max({ lst->max_sum, rst->max_sum, lst->suffix_max + rst->prefix_max });
    return n;
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    ll n;
    std::cin >> n;
    vll arr(n);
    loop(i, 0, n - 1){
        std::cin >> arr[i];
    }

    std::vector<Node*> seg(4 * n + 1);
    loop(i, 0, 4 * n) seg[i] = new Node();
    build(seg, arr, 0, n - 1, 0);

    ll m;
    std::cin >> m;
    while (m--){
        int l, r;
        std::cin >> l >> r;
        l--;
        r--;
        Node* ans = query(seg, 0, n - 1, 0, l, r);
        std::cout << ans->max_sum << "\n";
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}