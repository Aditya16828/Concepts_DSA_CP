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
#define all_loop(el, cont) for(auto &el:cont)

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

std::vector<std::list<pllll>> graph;

ll ans = 0;

ll helper(ll root, vb &vis, vll &count_nodes, ll &n) {
	count_nodes[root] = 1;
	vis[root] = true;
	all_loop(c, graph[root]) {
		if (vis[c.first]) continue;
		count_nodes[root] += helper(c.first, vis, count_nodes, n);
		ll wt = c.second;
		ans += (std::min(n - count_nodes[c.first], count_nodes[c.first]) * 2 * wt);
	}
	return count_nodes[root];
}

void findMaxDist(ll n) {
	vll count_nodes(n, 0);
	vb vis(n, 0);
	helper(0, vis, count_nodes, n);
	// return ans;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t;
	std::cin >> t;
	loop(test, 1, t) {
		ll n;
		std::cin >> n;
		graph.resize(n, std::list<pllll>());
		loop(i, 1, n - 1) {
			ll u, v, wt;
			std::cin >> u >> v >> wt;
			u--;
			v--;
			graph[u].push_back({v, wt});
			graph[v].push_back({u, wt});
		}
		// ll ans = 0;
		findMaxDist(n);
		std::cout << "Case #" << test << ": " << ans << "\n";
		graph.clear();
		ans = 0;
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
