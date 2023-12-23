<<<<<<< HEAD
// https://leetcode.com/problems/unique-paths/
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

class Solution {
public:
	int uniquePaths(int m, int n) {
		// dp[i][j] represents number of paths reqd to reach (m, n) from (i, j)
		// dp[i][j] = dp[i+1][j] + dp[i][j+1];
		std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
		dp[m][n] = 1;
		for (int i = m - 1; i >= 1; i--) {
			dp[i][n] = 1;
		}
		for (int j = n - 1; j >= 1; j--) {
			dp[m][j] = 1;
		}
		for (int i = m - 1; i >= 1; i--) {
			for (int j = n - 1; j >= 1; j--) {
				dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
			}
		}
		return dp[1][1];
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int m, n;
	std::cin >> m >> n;
	Solution s;
	log(s.uniquePaths(m, n));

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
=======
// https://leetcode.com/problems/unique-paths/
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

class Solution {
public:
	int uniquePaths(int m, int n) {
		// dp[i][j] represents number of paths reqd to reach (m, n) from (i, j)
		// dp[i][j] = dp[i+1][j] + dp[i][j+1];
		std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
		dp[m][n] = 1;
		for (int i = m - 1; i >= 1; i--) {
			dp[i][n] = 1;
		}
		for (int j = n - 1; j >= 1; j--) {
			dp[m][j] = 1;
		}
		for (int i = m - 1; i >= 1; i--) {
			for (int j = n - 1; j >= 1; j--) {
				dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
			}
		}
		return dp[1][1];
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int m, n;
	std::cin >> m >> n;
	Solution s;
	log(s.uniquePaths(m, n));

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
