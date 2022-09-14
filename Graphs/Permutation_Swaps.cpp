// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/permutation-swaps/
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

std::vector<std::list<ll>> g;

void dfs(ll root, vb &vis, vll &idx) {
	vis[root] = true;
	idx.push_back(root);
	iter_all(n, g[root]) {
		if (not vis[n]) {
			dfs(n, vis, idx);
		}
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t;
	std::cin >> t;
	while (t--) {
		ll n, m;
		std::cin >> n >> m;
		vll p(n), q(n);
		loop(i, 0, n - 1) {
			std::cin >> p[i];
		}
		loop(i, 0, n - 1) {
			std::cin >> q[i];
		}
		g.resize(n, std::list<ll>());
		while (m--) {
			ll u, v;
			std::cin >> u >> v; // indexes received
			u--;
			v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		vll idx; // stores the swappable indexes (connected component of indexes)
		vb vis(n, 0);
		bool flag = true;
		loop(i, 0, n - 1) {
			flag = true;
			if (not vis[i]) {
				dfs(i, vis, idx);

				std::unordered_set<ll> ele;

				loop(k, 0, idx.size() - 1) {
					ele.insert(p[idx[k]]);
				}

				loop(k, 0, idx.size() - 1) {
					if (ele.count(q[idx[k]]) == 0) {
						flag = false;
						break;
					}
				}

				idx.clear();
				if (not flag) break;
			}
		}
		if (flag) std::cout << "YES\n";
		else std::cout << "NO\n";
		g.clear();
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
