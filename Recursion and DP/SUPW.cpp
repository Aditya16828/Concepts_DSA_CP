<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

//std::vector<std::vector<ll>> dp;
ll min_sum(std::vector<ll> &v, int idx, int flag) {
	if (idx >= v.size()) {
		return 0;
	}
	//if (dp[idx][flag] != -1) return dp[idx][flag];
	if (flag == 2) {
		return /*dp[idx][flag] = */v[idx] + min_sum(v, idx + 1, 0);
	}
	ll inc = v[idx] + min_sum(v, idx + 1, 0);
	ll exc = min_sum(v, idx + 1, flag + 1);
	return /*dp[idx][flag] = */std::min(inc, exc);
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

	int n, idx = 0, min_val = INT_MAX;
	std::cin >> n;
	std::vector<ll> arr(n);
	//dp.resize(n + 1, std::vector<ll>(3, -1));
	for (int i = 0; i < n; i++) std::cin >> arr[i];
	std::cout << min_sum(arr, 0, 0) << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
=======
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

//std::vector<std::vector<ll>> dp;
ll min_sum(std::vector<ll> &v, int idx, int flag) {
	if (idx >= v.size()) {
		return 0;
	}
	//if (dp[idx][flag] != -1) return dp[idx][flag];
	if (flag == 2) {
		return /*dp[idx][flag] = */v[idx] + min_sum(v, idx + 1, 0);
	}
	ll inc = v[idx] + min_sum(v, idx + 1, 0);
	ll exc = min_sum(v, idx + 1, flag + 1);
	return /*dp[idx][flag] = */std::min(inc, exc);
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

	int n, idx = 0, min_val = INT_MAX;
	std::cin >> n;
	std::vector<ll> arr(n);
	//dp.resize(n + 1, std::vector<ll>(3, -1));
	for (int i = 0; i < n; i++) std::cin >> arr[i];
	std::cout << min_sum(arr, 0, 0) << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}