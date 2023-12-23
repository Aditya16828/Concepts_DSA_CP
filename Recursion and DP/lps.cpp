<<<<<<< HEAD
// https://leetcode.com/problems/longest-palindromic-subsequence/
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

// std::vector<std::vector<int>> dp;
// int lps(int i, int j, std::string &s) {
// 	if (i == j) return 1;
// 	if (s[i] == s[j] and (j - i + 1) == 2) return 2;

// 	if (dp[i][j] != -1) return dp[i][j];

// 	if (s[i] == s[j]) return dp[i][j] = helper(i + 1, j - 1, s) + 2;
// 	return dp[i][j] = std::max(helper(i + 1, j, s), helper(i, j - 1, s));
// }

int longestPalindromeSubseq(std::string &s) {
	int n = s.size();
	std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

	// of length = 1 (i == j)
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}

	for (int len = 2; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + (len - 1);

			// of length of window = 2 (s[i] == s[j] and j-i+1 == 2)
			if (s[i] == s[j] and len == 2) {
				dp[i][j] = 2;
			}
			// for case (s[i] == s[j] and j-i+1 > 2)
			else if (s[i] == s[j]) {
				dp[i][j] = dp[i + 1][j - 1] + 2;
			} else {
				dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[0][n - 1];
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	std::string s;
	std::cin >> s;

	// int n = s.size();
	// dp.resize(n + 1, std::vector<int>(n + 1, -1));
	// std::cout << lps(0, n - 1, s) << "\n";
	std::cout << longestPalindromeSubseq(s) << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
=======
// https://leetcode.com/problems/longest-palindromic-subsequence/
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

// std::vector<std::vector<int>> dp;
// int lps(int i, int j, std::string &s) {
// 	if (i == j) return 1;
// 	if (s[i] == s[j] and (j - i + 1) == 2) return 2;

// 	if (dp[i][j] != -1) return dp[i][j];

// 	if (s[i] == s[j]) return dp[i][j] = helper(i + 1, j - 1, s) + 2;
// 	return dp[i][j] = std::max(helper(i + 1, j, s), helper(i, j - 1, s));
// }

int longestPalindromeSubseq(std::string &s) {
	int n = s.size();
	std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

	// of length = 1 (i == j)
	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}

	for (int len = 2; len <= n; len++) {
		for (int i = 0; i <= n - len; i++) {
			int j = i + (len - 1);

			// of length of window = 2 (s[i] == s[j] and j-i+1 == 2)
			if (s[i] == s[j] and len == 2) {
				dp[i][j] = 2;
			}
			// for case (s[i] == s[j] and j-i+1 > 2)
			else if (s[i] == s[j]) {
				dp[i][j] = dp[i + 1][j - 1] + 2;
			} else {
				dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[0][n - 1];
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	std::string s;
	std::cin >> s;

	// int n = s.size();
	// dp.resize(n + 1, std::vector<int>(n + 1, -1));
	// std::cout << lps(0, n - 1, s) << "\n";
	std::cout << longestPalindromeSubseq(s) << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
