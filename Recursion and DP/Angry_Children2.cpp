// https://www.hackerrank.com/challenges/angry-children-2/problem
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
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

	int n, k;
	std::cin >> n >> k;
	std::vector<ll> arr(n);
	for (int i = 0; i < n; i++) std::cin >> arr[i];
	std::sort(arr.begin(), arr.end());
	// logarr(arr, 0, n - 1);

	// set prefix;
	std::vector<ll> prefix(arr);
	for (int i = 1; i < n; i++) {
		prefix[i] += prefix[i - 1];
	}
	// logarr(prefix, 0, n - 1);

	ll ans = 0, res = inf;

	int i = 1;
	for (; i < k; i++) {
		ans += ((arr[i] * (i)) - prefix[i - 1]);
		// std::cout << ans << ", ";
	}
	res = std::min(res, ans);

	while (i < n) {
		ans += (((k - 1) * arr[i - k]) - (prefix[i - 1] - prefix[i - k]));
		ans += ((k - 1) * arr[i]) - ((prefix[i - 1] - prefix[i - k]));
		++i;
		res = std::min(res, ans);
	}

	std::cout << res << "\n";


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
