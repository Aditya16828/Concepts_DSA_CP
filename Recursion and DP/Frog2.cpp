<<<<<<< HEAD
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

// ll dp[100005];
// ll cost(int i, int k, int n, std::vector<int> &h) {
// 	if (i == 0) return 0;
// 	if (dp[i] != -1) return dp[i];
// 	ll ans = INT64_MAX;
// 	for (int j = 1; j <= k; j++) {
// 		if (i - j < 0) break;
// 		else
// 			ans = std::min(ans, abs(h[i] - h[i - j]) + cost(i - j, k, n, h));
// 	}
// 	return dp[i] = ans;
// }

ll cost_BU(int k, int n, std::vector<int> &h) {
	std::vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i - j < 0) break;
			dp[i] = std::min(dp[i], abs(h[i] - h[i - j]) + dp[i - j]);
		}
	}
	return dp[n - 1];
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n, k;
	std::cin >> n >> k;
	std::vector<int> h(n);
	for (int i = 0; i < n; i++) {
		std::cin >> h[i];
	}
	// std::memset(dp, -1, sizeof dp);
	// std::cout << cost(n - 1, k, n, h) << "\n";
	std::cout << cost_BU(k, n, h) << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
=======
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

// ll dp[100005];
// ll cost(int i, int k, int n, std::vector<int> &h) {
// 	if (i == 0) return 0;
// 	if (dp[i] != -1) return dp[i];
// 	ll ans = INT64_MAX;
// 	for (int j = 1; j <= k; j++) {
// 		if (i - j < 0) break;
// 		else
// 			ans = std::min(ans, abs(h[i] - h[i - j]) + cost(i - j, k, n, h));
// 	}
// 	return dp[i] = ans;
// }

ll cost_BU(int k, int n, std::vector<int> &h) {
	std::vector<int> dp(n, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (i - j < 0) break;
			dp[i] = std::min(dp[i], abs(h[i] - h[i - j]) + dp[i - j]);
		}
	}
	return dp[n - 1];
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n, k;
	std::cin >> n >> k;
	std::vector<int> h(n);
	for (int i = 0; i < n; i++) {
		std::cin >> h[i];
	}
	// std::memset(dp, -1, sizeof dp);
	// std::cout << cost(n - 1, k, n, h) << "\n";
	std::cout << cost_BU(k, n, h) << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
