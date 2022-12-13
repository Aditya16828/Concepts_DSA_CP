// https://cses.fi/problemset/task/1633
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

ll dice[6] = {1, 2, 3, 4, 5, 6};
std::vector<ll> dp;
ll ways(int n) {
	if (n == 0) return 1;
	if (n < 0) return 0;
	if (dp[n] != -1) return dp[n];
	ll res = 0;
	for (ll j = 0; j < 6; j++) {
		res = ((res % mod) + (ways(n - dice[j]) % mod));
	}
	return dp[n] = res % mod;
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

	int n;
	std::cin >> n;
	dp.resize(n + 1, -1);
	std::cout << ways(n) << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}