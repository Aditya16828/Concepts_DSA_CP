// https://www.spoj.com/problems/MPILOT/
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

std::vector<std::vector<ll>> dp;
int f(int i, int a, int c, int n, std::vector<ll> &as, std::vector<ll> &cap) {
	if (i == n) return 0;
	if (dp[i][a] != -1) return dp[i][a];
	if (a == c) {
		return dp[i][a] = f(i + 1, a - 1, c, n, as, cap) + as[i];
	}
	if (a == 0) {
		return dp[i][a] = f(i + 1, a, c - 1, n, as, cap) + cap[i];
	}
	return dp[i][a] = std::min(f(i + 1, a - 1, c, n, as, cap) + as[i], f(i + 1, a, c - 1, n, as, cap) + cap[i]);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin >> n;
	std::vector<ll> cap(n), as(n);
	for (int i = 0; i < n; i++) {
		std::cin >> cap[i] >> as[i];
	}
	dp.resize(n + 1, std::vector<ll>(10005, -1));
	std::cout << as[0] + f(1, (n / 2) - 1, n / 2, n, as, cap);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
