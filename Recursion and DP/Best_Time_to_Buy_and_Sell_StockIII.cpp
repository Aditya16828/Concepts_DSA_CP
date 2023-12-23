<<<<<<< HEAD
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
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
	int dp[100002][3][3];
	int helper(int i, int b, int trans, std::vector<int> &prices) {
		if (i == prices.size()) return 0;

		if (dp[i][b][trans] != -1) return dp[i][b][trans];

		// not pick
		int np = helper(i + 1, b, trans, prices);

		// pick
		int p = 0;
		if (b == 0 and trans > 0) {
			p = std::max(p, helper(i, 1, trans - 1, prices) - prices[i]);
		} else if (b == 1) {
			p = std::max(p, helper(i + 1, 0, trans, prices) + prices[i]);
		}
		return dp[i][b][trans] = std::max(p, np);
	}
public:
	int maxProfit(vector<int>& prices) {
		std::memset(dp, -1, sizeof dp);
		return helper(0, 0, 2, prices);
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....



#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
=======
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
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
	int dp[100002][3][3];
	int helper(int i, int b, int trans, std::vector<int> &prices) {
		if (i == prices.size()) return 0;

		if (dp[i][b][trans] != -1) return dp[i][b][trans];

		// not pick
		int np = helper(i + 1, b, trans, prices);

		// pick
		int p = 0;
		if (b == 0 and trans > 0) {
			p = std::max(p, helper(i, 1, trans - 1, prices) - prices[i]);
		} else if (b == 1) {
			p = std::max(p, helper(i + 1, 0, trans, prices) + prices[i]);
		}
		return dp[i][b][trans] = std::max(p, np);
	}
public:
	int maxProfit(vector<int>& prices) {
		std::memset(dp, -1, sizeof dp);
		return helper(0, 0, 2, prices);
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....



#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
