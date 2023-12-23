// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/practice-problems/algorithm/shivam-and-expensive-birthday-gift-da58b2f0/?purpose=login&source=problem-page&update=github
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(ll z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define vll std::vector<long long ll>
#define vi std::vector<int>
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

std::vector<ll> arr, tree;

void update(ll idx, ll inc_val, ll nl, ll nr, ll tidx){
	if(nl == nr){
		if(arr[idx] == 0 and inc_val < 0) return;
		arr[idx] += inc_val;
		tree[tidx] += inc_val;
        return;
	}

	ll mid = nl + (nr-nl)/2;
	if(idx <= mid) update(idx, inc_val, nl, mid, 2*tidx+1);
	else update(idx, inc_val, mid+1, nr, 2*tidx+2);
	tree[tidx] = tree[2*tidx+1]+tree[2*tidx+2];
}

ll query(ll l, ll r, ll nl, ll nr, ll tidx){
	if(r < nl or l > nr){
		return 0;
	}
	if(nl >= l and nr <= r){
		return tree[tidx];
	}

	ll mid = nl + (nr-nl)/2;
	ll ans1 = query(l, r, nl, mid, 2*tidx+1);
	ll ans2 = query(l, r, mid+1, nr, 2*tidx+2);
	return ans1+ans2;
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    ll n, q;
	std::cin>>n>>q;

	tree.resize(4*n, 0);
	arr.resize(n, 0);

	while(q--){
		ll type;
		std::cin>>type;
		if(type == 1 or type == 2){
			ll x;
			std::cin>>x;
			x--;
			if(type == 1) update(x, 1, 0, n-1, 0);
			if(type == 2) update(x, -1, 0, n-1, 0);
		} else {
			ll x, y;
			std::cin>>x>>y;
			x--;
			y--;
			std::cout<<query(x, y, 0, n-1, 0)<<"\n";
		}
	}

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}