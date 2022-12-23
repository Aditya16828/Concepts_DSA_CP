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
	int minDistance(std::string &word1, std::string &word2) {
		int w1 = word1.size();
		int w2 = word2.size();
		std::vector<std::vector<int>> dp(w1 + 1, std::vector<int>(w2 + 1, 0));
		for (int i = 0; i <= w1; i++) dp[i][0] = i;
		for (int i = 0; i <= w2; i++) dp[0][i] = i;
		for (int i = 1; i <= w1; i++) {
			for (int j = 1; j <= w2; j++) {
				if (word1[i - 1] == word2[j - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				} else {
					dp[i][j] = 1 + std::min({dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]});
				}
			}
		}
		// std::cout << dp[w1][w2] << "\n";
		return dp[w1][w2];
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	std::string word1, word2;
	std::cin >> word1 >> word2;
	Solution s;
	std::cout << s.minDistance(word1, word2) << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
