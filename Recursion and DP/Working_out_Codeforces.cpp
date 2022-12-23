// https://codeforces.com/problemset/problem/429/B
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

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

int maxGain(std::vector<std::vector<int>> &arr, int n, int m) {
	std::vector<std::vector<ll>> a(n + 2, std::vector<ll>(m + 2, 0)); // f
	std::vector<std::vector<ll>> b(n + 2, std::vector<ll>(m + 2, 0)); // h
	std::vector<std::vector<ll>> c(n + 2, std::vector<ll>(m + 2, 0)); // g
	std::vector<std::vector<ll>> d(n + 2, std::vector<ll>(m + 2, 0)); // a

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = arr[i][j] + std::max(a[i - 1][j], a[i][j - 1]);
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			c[i][j] = arr[i][j] + std::max(c[i + 1][j], c[i][j + 1]);
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			b[i][j] = arr[i][j] + std::max(b[i + 1][j], b[i][j - 1]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			d[i][j] = arr[i][j] + std::max(d[i - 1][j], d[i][j + 1]);
		}
	}
	ll ans = INT_MIN;

	for (int i = 2; i < n; i++) {
		for (int j = 2; j < m; j++) {
			ans = std::max(ans, a[i][j - 1] + c[i][j + 1] + b[i + 1][j] + d[i - 1][j]);
			ans = std::max(ans, a[i - 1][j] + c[i + 1][j] + b[i][j - 1] + d[i][j + 1]);
		}
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> a(n + 2, std::vector<int>(m + 2, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
		}
	}
	std::cout << maxGain(a, n, m) << "\n";


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
