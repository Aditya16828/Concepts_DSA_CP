// https://www.hackerrank.com/challenges/the-power-sum/problem
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

int expo(int base, int exp) {
	if (exp == 0) return 1;
	if (exp == 1) return base;
	int res = 1;
	while (exp) {
		if (exp % 2) {
			res = res * base;
		}
		base = base * base;
		exp /= 2;
	}
	return res;
}

int powerSum(int i, int x, int n) {
	if (x < 0) {
		return 0;
	}
	if (x == 0) {
		return 1;
	}
	int inc = powerSum(i + 1, x - expo(i, n), n);
	int exc = powerSum(i + 1, x, n);
	return (inc + exc);
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

	int x, n;
	std::cin >> x >> n;
	std::cout << powerSum(1, x, n) << "\n";
	//std::cout << pow(x, n);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}