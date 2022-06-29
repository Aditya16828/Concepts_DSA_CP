// https://www.lintcode.com/problem/776/
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

std::vector<std::string> helper(int n, int len) {
	if (n == 0) return {""};
	if (n == 1) return {"1", "8", "0"};
	std::vector<std::string> res;
	std::vector<std::string> vec_n_2 = helper(n - 2, len);
	for (auto &x : vec_n_2) {
		res.push_back("1" + x + "1");
		res.push_back("8" + x + "8");
		res.push_back("6" + x + "9");
		res.push_back("9" + x + "6");
		if (n != len) res.push_back("0" + x + "0");
	}
	return res;
}

std::vector<std::string> findStrobogrammatic(int n) {
	return helper(n, n);
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
	for (auto &i : findStrobogrammatic(n)) {
		std::cout << i << ", ";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}