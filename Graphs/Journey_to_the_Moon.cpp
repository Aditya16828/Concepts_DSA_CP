<<<<<<< HEAD
// https://www.hackerrank.com/challenges/journey-to-the-moon/problem
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

void dfs(ll root, vb &vis, ll &no) {
	vis[root] = true;
	++no;
	iter_all(n, g[root]) {
		if (not vis[n]) {
			dfs(n, vis, no);
		}
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	ll n, p;
	std::cin >> n >> p;
	g.resize(n, std::list<ll>());
	while (p--) {
		ll u, v;
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll total = (n * (n - 1)) / 2;
	// ans = total number of choices - number of choices from the same country
	// hence I need to find out the number of nodes in each connected component
	vb vis(n, 0);
	loop(i, 0, n - 1) {
		if (not vis[i]) {
			ll no_nodes = 0;
			dfs(i, vis, no_nodes);
			total -= (no_nodes * (no_nodes - 1)) / 2;
		}
	}
	std::cout << total << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
=======
// https://www.hackerrank.com/challenges/journey-to-the-moon/problem
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

void dfs(ll root, vb &vis, ll &no) {
	vis[root] = true;
	++no;
	iter_all(n, g[root]) {
		if (not vis[n]) {
			dfs(n, vis, no);
		}
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	ll n, p;
	std::cin >> n >> p;
	g.resize(n, std::list<ll>());
	while (p--) {
		ll u, v;
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll total = (n * (n - 1)) / 2;
	// ans = total number of choices - number of choices from the same country
	// hence I need to find out the number of nodes in each connected component
	vb vis(n, 0);
	loop(i, 0, n - 1) {
		if (not vis[i]) {
			ll no_nodes = 0;
			dfs(i, vis, no_nodes);
			total -= (no_nodes * (no_nodes - 1)) / 2;
		}
	}
	std::cout << total << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
