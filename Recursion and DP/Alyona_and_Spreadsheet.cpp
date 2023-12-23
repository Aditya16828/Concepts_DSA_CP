<<<<<<< HEAD
// https://codeforces.com/problemset/problem/777/C?mobile=false
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

void set_dp(std::vector<std::vector<ll>> &dp, std::vector<std::vector<ll>> &arr) {
	int n = dp.size();
	int m = dp[0].size();
	for (int i = 0; i < m; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] >= arr[i - 1][j]) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = i;
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<ll>> arr(n, std::vector<ll>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> arr[i][j];
		}
	}

	int k;
	std::cin >> k;
	std::vector<std::vector<ll>> dp(n, std::vector<ll>(m, 0));

	set_dp(dp, arr);

	std::vector<ll> min_ele_row(n);
	for (int i = 0; i < n; i++) {
		min_ele_row[i] = *min_element(dp[i].begin(), dp[i].end());
	}

	// logarr(min_ele_row, 0, min_ele_row.size() - 1);

	while (k--) {
		int l, r;
		std::cin >> l >> r;
		l--;
		r--;
		std::string ans;
		if (l == r) ans = "Yes";
		else {
			if (min_ele_row[r] <= l) ans = "Yes";
			else ans = "No";
		}

		std::cout << (ans) << "\n";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
=======
// https://codeforces.com/problemset/problem/777/C?mobile=false
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

void set_dp(std::vector<std::vector<ll>> &dp, std::vector<std::vector<ll>> &arr) {
	int n = dp.size();
	int m = dp[0].size();
	for (int i = 0; i < m; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] >= arr[i - 1][j]) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = i;
			}
		}
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<ll>> arr(n, std::vector<ll>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> arr[i][j];
		}
	}

	int k;
	std::cin >> k;
	std::vector<std::vector<ll>> dp(n, std::vector<ll>(m, 0));

	set_dp(dp, arr);

	std::vector<ll> min_ele_row(n);
	for (int i = 0; i < n; i++) {
		min_ele_row[i] = *min_element(dp[i].begin(), dp[i].end());
	}

	// logarr(min_ele_row, 0, min_ele_row.size() - 1);

	while (k--) {
		int l, r;
		std::cin >> l >> r;
		l--;
		r--;
		std::string ans;
		if (l == r) ans = "Yes";
		else {
			if (min_ele_row[r] <= l) ans = "Yes";
			else ans = "No";
		}

		std::cout << (ans) << "\n";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
