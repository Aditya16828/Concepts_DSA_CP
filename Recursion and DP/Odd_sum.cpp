<<<<<<< HEAD
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)
#define inf (ll)1e10

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
	std::vector<ll> arr(n);
	ll sum = 0;
	ll max_odd_neg = -inf, min_odd_pos = inf;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
		if (arr[i] > 0) sum += arr[i];
		if (arr[i] % 2 != 0) {
			if (arr[i] < 0) max_odd_neg = std::max(max_odd_neg, arr[i]);
			if (arr[i] > 0) min_odd_pos = std::min(min_odd_pos, arr[i]);
		}
	}
	ll ans = -inf;
	if (sum % 2 == 0) {
		ans = sum - std::min((ll)abs(max_odd_neg), min_odd_pos);
	} else ans = sum;
	std::cout << ans << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
=======
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)
#define inf (ll)1e10

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
	std::vector<ll> arr(n);
	ll sum = 0;
	ll max_odd_neg = -inf, min_odd_pos = inf;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
		if (arr[i] > 0) sum += arr[i];
		if (arr[i] % 2 != 0) {
			if (arr[i] < 0) max_odd_neg = std::max(max_odd_neg, arr[i]);
			if (arr[i] > 0) min_odd_pos = std::min(min_odd_pos, arr[i]);
		}
	}
	ll ans = -inf;
	if (sum % 2 == 0) {
		ans = sum - std::min((ll)abs(max_odd_neg), min_odd_pos);
	} else ans = sum;
	std::cout << ans << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}