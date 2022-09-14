// https://cses.fi/problemset/task/1674/
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

std::vector<std::vector<int>> graph;
std::vector<ll> dp;

ll count_subord(int src, int parent = -1) {
	if (dp[src] != -1) return dp[src];
	ll ans = 0;
	bool leaf = true;
	for (auto &n : graph[src]) {
		if (n == parent) continue;
		leaf = false;
		ans += count_subord(n, src);
	}
	return dp[src] = (ans + 1);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin >> n;
	graph.resize(n + 1, std::vector<int>());
	for (int i = 2; i <= n; i++) {
		int x;
		std::cin >> x;
		graph[i].push_back(x);
		graph[x].push_back(i);
	}
	dp.resize(n + 1, -1);
	count_subord(1);
	for (int i = 1; i <= n; i++) {
		std::cout << dp[i] - 1 << " "; // -1 as dp[] stores the number of nodes in the particular subtree including the parent
		// but in question we need to print only its number of child
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
