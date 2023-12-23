// https://cses.fi/problemset/task/1638
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

std::vector<std::string> grid;
std::vector<std::vector<ll>> dp;
bool isSafe(int x, int y, int n) {
	return (x >= 0 and x < n and y >= 0 and y < n and grid[x][y] != '*');
}

ll calculate_paths(int x, int y, int n) {
	if (x == n - 1 and y == n - 1) {
		return 1;
	}
	if (dp[x][y] != -1)
		return dp[x][y];
	ll way1 = 0, way2 = 0;
	if (isSafe(x + 1, y, n)) way1 = calculate_paths(x + 1, y, n) % mod;
	if (isSafe(x, y + 1, n)) way2 = calculate_paths(x, y + 1, n) % mod;
	return dp[x][y] = (way1 + way2) % mod;
}

int main() {
	clock_t begin = clock();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	std::cin >> n;
	grid.resize(n);
	dp.resize(n, std::vector<ll>(n, -1));
	for (int i = 0; i < n; i++) {
		std::cin >> grid[i];
	}
	ll paths = 0;
	if (isSafe(n - 1, n - 1, n) and isSafe(0, 0, n)) {
		paths = calculate_paths(0, 0, n);
	}
	std::cout << paths << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}