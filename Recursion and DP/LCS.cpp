<<<<<<< HEAD
// https://atcoder.jp/contests/dp/tasks/dp_f
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

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	std::string s, t;
	std::cin >> s >> t;
	int s_len = s.size();
	int t_len = t.size();
	std::vector<std::vector<int>> dp(s_len + 1, std::vector<int>(t_len + 1, 0));
	for (int i = 1; i <= s_len; i++) {
		for (int j = 1; j <= t_len; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	// std::cout << dp[s_len][t_len] << "\n";
	// for (int i = 0; i <= s_len; i++) {
	// 	for (int j = 0; j <= t_len; j++) {
	// 		std::cout << dp[i][j] << " ";
	// 	}
	// 	std::cout << "\n";
	// }

	std::string ans = "";
	int i = s_len, j = t_len;
	while (i >= 1 and j >= 1) {
		if (s[i - 1] == t[j - 1]) {
			ans = t[j - 1] + ans;
			i--;
			j--;
		} else {
			if (dp[i - 1][j] > dp[i][j - 1]) {
				i--;
			} else {
				j--;
			}
		}
	}
	std::cout << ans << "\n";


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
=======
// https://atcoder.jp/contests/dp/tasks/dp_f
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

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	std::string s, t;
	std::cin >> s >> t;
	int s_len = s.size();
	int t_len = t.size();
	std::vector<std::vector<int>> dp(s_len + 1, std::vector<int>(t_len + 1, 0));
	for (int i = 1; i <= s_len; i++) {
		for (int j = 1; j <= t_len; j++) {
			if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	// std::cout << dp[s_len][t_len] << "\n";
	// for (int i = 0; i <= s_len; i++) {
	// 	for (int j = 0; j <= t_len; j++) {
	// 		std::cout << dp[i][j] << " ";
	// 	}
	// 	std::cout << "\n";
	// }

	std::string ans = "";
	int i = s_len, j = t_len;
	while (i >= 1 and j >= 1) {
		if (s[i - 1] == t[j - 1]) {
			ans = t[j - 1] + ans;
			i--;
			j--;
		} else {
			if (dp[i - 1][j] > dp[i][j - 1]) {
				i--;
			} else {
				j--;
			}
		}
	}
	std::cout << ans << "\n";


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
