// https://atcoder.jp/contests/dp/tasks/dp_g
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

std::vector<std::list<int>> graph;

int dp[(int)(1e5 + 5)];

int longestPath(int src) {
	if (dp[src] != -1) return dp[src];
	int ans = INT_MIN;
	for (auto &ne : graph[src]) {
		ans = std::max(ans, longestPath(ne));
	}
	if (ans == INT_MIN) return dp[src] = 0;
	return dp[src] = ans + 1;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n, m;
	std::cin >> n >> m;
	graph.resize(n + 1, std::list<int>());
	loop(_, 1, m) {
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		// graph[v].push_back(u);
	}

	// loop(i, 1, graph.size() - 1) {
	// 	std::cout << i << "->";
	// 	iter_all(el, graph[i]) std::cout << el << ", ";
	// 	std::cout << "\n";
	// }
	vb vis(n + 1, 0);
	int ans = INT_MIN;
	std::memset(dp, -1, sizeof dp);
	loop(i, 1, n) {
		ans = std::max(ans, longestPath(i));
	}
	std::cout << ans << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}