// https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define vll std::vector<long long int>
#define vi std::vector<int>
#define vb std::vector<bool>
#define pii std::pair<int, int>
#define pllll std::pair<long long int, long long int>
#define loop(i, a, b) for(int i=a;i<=b;i++)
#define rloop(i, a, b) for(int i=a;i>=b;i--)
#define iter_all(el, cont) for(auto &el:cont)

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
	std::vector<std::vector<int>> dp;
	int helper(int i, int j, std::vector<int> &arr) {
		// if(arr[i] >= arr[j]) return 0;
		if (dp[i][j] != -1) return dp[i][j];
		int ans = INT_MAX;
		for (int k = i + 1; k <= j - 1; k++) {
			ans = std::min(ans, helper(i, k, arr) + helper(k, j, arr) + (arr[j] - arr[i]));
		}
		if (ans == INT_MAX) ans = 0;
		return dp[i][j] = ans;
	}
public:
	int minCost(int n, vector<int>& cuts) {
		cuts.push_back(n);
		cuts.insert(cuts.begin(), 0);
		int sz = cuts.size();
		std::sort(cuts.begin(), cuts.end());
		for (int i = 0; i < sz; i++) std::cout << cuts[i] << ", ";
		dp.resize(cuts.size() + 1, std::vector<int>(cuts.size() + 1, -1));
		return helper(0, sz - 1, cuts);
		// return 0;
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
