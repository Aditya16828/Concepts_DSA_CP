// https://atcoder.jp/contests/dp/tasks/dp_p
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

std::vector<std::list<ll>> g;

ll dp[(ll)(1e5 + 5)][2];

ll paint(ll node, ll c, ll parent = -1) {
	if (dp[node][c] != -1) return dp[node][c];
	ll ans = 1;
	for (auto &child : g[node]) {
		if (child == parent) continue;
		if (c == 0) { // parent is white
			ans = (ans % mod * (paint(child, 0, node) % mod + paint(child, 1, node) % mod)) % mod;
		} else { // parent is black
			ans = (ans % mod * paint(child, 0, node) % mod) % mod;
		}
	}
	return dp[node][c] = ans % mod;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin >> n;
	g.resize(n + 1, std::list<ll>());
	loop(i, 1, n - 1) {
		ll x, y;
		std::cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	std::memset(dp, -1, sizeof dp);
	ll ans = paint(1, 0) % mod + paint(1, 1) % mod;
	std::cout << ans % mod << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}