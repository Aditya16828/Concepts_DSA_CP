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

int Get(vll &leader, ll a) {
	return leader[a] = leader[a] == a ? a : Get(leader, leader[a]);
}

void Union(vll &leader, vll &sz, ll a, ll b) {
	a = Get(leader, a);
	b = Get(leader, b);
	if (a == b) {
		return;
	}
	// log("Before");
	// log(sz[a], sz[b]);
	if (sz[a] > sz[b]) {
		sz[a] += sz[b];
		leader[b] = a;
	} else {
		sz[b] += sz[a];
		leader[a] = b;
	}
	// log("After");
	// log(sz[a], sz[b]);
	// logarr(sz, 0, sz.size() - 1);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	ll n;
	std::cin >> n;
	vll leader(n);
	vll sz(n, 1);
	loop(i, 0, n - 1) {
		leader[i] = i;
	}
	ll p;
	std::cin >> p;
	while (p--) {
		ll u, v;
		std::cin >> u >> v;
		Union(leader, sz, u, v);
	}
	vb visited(n, 0);
	ll total = ((n * (n - 1)) / 2);
	loop(i, 0, n - 1) {
		ll x = Get(leader, i);
		// log(i, x);
		// std::cout << i << ", " << x << " " << sz[x] << "\n";
		if (not visited[x]) {
			total -= ((sz[x] * (sz[x] - 1)) / 2);
			visited[x] = true;
		}
	}
	// logarr(leader, 0, n - 1);
	std::cout << total << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
