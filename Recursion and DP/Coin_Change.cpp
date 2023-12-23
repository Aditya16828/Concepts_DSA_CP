<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

std::vector<int> dp;
int helper(std::vector<int> &coins, int amt) {
	if (amt < 0) return INT_MAX;
	if (amt == 0) return 0;
	if (dp[amt] != -1) return dp[amt];
	int currVal = INT_MAX;
	for (int i = 0; i < coins.size(); i++) {
		if (amt - coins[i] < 0) continue;
		currVal = std::min(currVal, helper(coins, amt - coins[i]));
	}
	return dp[amt] = ((currVal == INT_MAX) ? INT_MAX : 1 + currVal);
}

int coinChange(std::vector<int>& coins, int amount) {
	dp.resize(amount + 1, -1);
	int value = helper(coins, amount);
	return (value == INT_MAX ? -1 : value);
}

int main()
{
	clock_t begin = clock();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, amount;
	std::cin >> n >> amount;
	std::vector<int> coins(n);
	for (int i = 0; i < n; i++) std::cin >> coins[i];
	std::cout << coinChange(coins, amount);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
=======
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

std::vector<int> dp;
int helper(std::vector<int> &coins, int amt) {
	if (amt < 0) return INT_MAX;
	if (amt == 0) return 0;
	if (dp[amt] != -1) return dp[amt];
	int currVal = INT_MAX;
	for (int i = 0; i < coins.size(); i++) {
		if (amt - coins[i] < 0) continue;
		currVal = std::min(currVal, helper(coins, amt - coins[i]));
	}
	return dp[amt] = ((currVal == INT_MAX) ? INT_MAX : 1 + currVal);
}

int coinChange(std::vector<int>& coins, int amount) {
	dp.resize(amount + 1, -1);
	int value = helper(coins, amount);
	return (value == INT_MAX ? -1 : value);
}

int main()
{
	clock_t begin = clock();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, amount;
	std::cin >> n >> amount;
	std::vector<int> coins(n);
	for (int i = 0; i < n; i++) std::cin >> coins[i];
	std::cout << coinChange(coins, amount);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}