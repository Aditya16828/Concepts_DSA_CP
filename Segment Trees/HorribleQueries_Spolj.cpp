// https://www.spoj.com/problems/HORRIBLE/
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

void update(std::vector<ll> &arr, std::vector<ll> &tree, std::vector<ll> &loan, ll start, ll end, ll l, ll r, ll val, ll tidx){
    if(loan[tidx] != 0){
        tree[tidx] += loan[tidx]*(end-start+1);
        if(start != end){
            loan[2*tidx+1] += loan[tidx];
            loan[2*tidx+2] += loan[tidx];
        }
        loan[tidx] = 0;
    }
    if(start > r or end < l){
        return;
    }

    if(start >= l and end <= r){
        tree[tidx] += val*(end-start+1);
        if(start != end){
            loan[2*tidx+1] += val;
            loan[2*tidx+2] += val;
        }

        return;
    }

    ll mid = start + (end-start)/2;
    update(arr, tree, loan, start, mid, l, r, val, 2*tidx+1);
    update(arr, tree, loan, mid+1, end, l, r, val, 2*tidx+2);
    tree[tidx] = tree[2*tidx+1] + tree[2*tidx+2];
}

ll query(std::vector<ll> &arr, std::vector<ll> &tree, std::vector<ll> &loan, ll start, ll end, ll l, ll r, ll tidx){
    if(loan[tidx] != 0){
        tree[tidx] += loan[tidx]*(end-start+1);
        if(start != end){
            loan[2*tidx+1] += loan[tidx];
            loan[2*tidx+2] += loan[tidx];
        }
        loan[tidx] = 0;
    }

    if(start > r or end < l){
        return 0;
    }

    if(start >= l and end <= r){
        return tree[tidx];
    }

    ll mid = start + (end-start)/2;
    ll left = query(arr, tree, loan, start, mid, l, r, 2*tidx+1);
    ll right = query(arr, tree, loan, mid+1, end, l, r, 2*tidx+2);
    return left+right;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    int t;
    std::cin>>t;
    while(t--){
        ll n;
        std::cin>>n;
        std::vector<ll> arr(n, 0);
        std::vector<ll> tree(4*n, 0);
        std::vector<ll> loan(4*n, 0);
        ll c;
        std::cin>>c;
        while(c--){
            ll type;
            std::cin>>type;
            if(type == 0){
                ll p, q, v;
                std::cin>>p>>q>>v;
                // update
                update(arr, tree, loan, 0, n-1, p-1, q-1, v, 0);
            } else {
                ll p, q;
                std::cin>>p>>q;
                // query
                std::cout<<query(arr, tree, loan, 0, n-1, p-1, q-1, 0)<<"\n";
            }
        }
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}