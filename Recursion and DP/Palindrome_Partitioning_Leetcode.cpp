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

class Solution {
	std::vector<std::vector<bool>> dp;
	std::vector<std::vector<std::string>> res;
	std::vector<std::string> ans;
	void helper(int i, std::string &s) {
		if (i == s.size()) {
			res.push_back(ans);
			// for (auto &x : ans)
			// 	std::cout << x << ", ";
			// std::cout << "\n";
			return;
		}

		int n = s.size();
		for (int j = i; j < n; j++) {
			if (dp[i][j]) {
				std::string temp = s.substr(i, j - i + 1);
				ans.push_back(temp);
				// std::string ros = s.substr(j + 1);
				// log(ros);
				helper(j + 1, s);
				ans.pop_back();
			}
		}
	}
public:
	std::vector<std::vector<std::string>> partition(std::string s) {
		int n = s.size();
		dp.resize(n, std::vector<bool>(n, false));

		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
		}
		for (int len = 2; len <= n; len++) {
			for (int i = 0; i <= n - len; i++) {
				int j = i + (len - 1);
				if (s[i] == s[j] and len == 2) {
					dp[i][j] = true;
				} else if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] and (s[i] == s[j]);
				}
			}
		}

		// for (auto &r : dp) {
		// 	for (auto el : r) {
		// 		std::cout << el << " ";
		// 	}
		// 	std::cout << "\n";
		// }

		helper(0, s);
		return res;
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	Solution sol;
	std::string str;
	std::cin >> str;
	std::vector<std::vector<std::string>> result = sol.partition(str);
	for (int i = 0; i < (int)result.size(); i++) {
		for (auto &x : result[i]) {
			std::cout << x << ", ";
		}
		std::cout << "\n";
	}


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

class Solution {
	std::vector<std::vector<bool>> dp;
	std::vector<std::vector<std::string>> res;
	std::vector<std::string> ans;
	void helper(int i, std::string &s) {
		if (i == s.size()) {
			res.push_back(ans);
			// for (auto &x : ans)
			// 	std::cout << x << ", ";
			// std::cout << "\n";
			return;
		}

		int n = s.size();
		for (int j = i; j < n; j++) {
			if (dp[i][j]) {
				std::string temp = s.substr(i, j - i + 1);
				ans.push_back(temp);
				// std::string ros = s.substr(j + 1);
				// log(ros);
				helper(j + 1, s);
				ans.pop_back();
			}
		}
	}
public:
	std::vector<std::vector<std::string>> partition(std::string s) {
		int n = s.size();
		dp.resize(n, std::vector<bool>(n, false));

		for (int i = 0; i < n; i++) {
			dp[i][i] = true;
		}
		for (int len = 2; len <= n; len++) {
			for (int i = 0; i <= n - len; i++) {
				int j = i + (len - 1);
				if (s[i] == s[j] and len == 2) {
					dp[i][j] = true;
				} else if (s[i] == s[j]) {
					dp[i][j] = dp[i + 1][j - 1] and (s[i] == s[j]);
				}
			}
		}

		// for (auto &r : dp) {
		// 	for (auto el : r) {
		// 		std::cout << el << " ";
		// 	}
		// 	std::cout << "\n";
		// }

		helper(0, s);
		return res;
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	Solution sol;
	std::string str;
	std::cin >> str;
	std::vector<std::vector<std::string>> result = sol.partition(str);
	for (int i = 0; i < (int)result.size(); i++) {
		for (auto &x : result[i]) {
			std::cout << x << ", ";
		}
		std::cout << "\n";
	}


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
