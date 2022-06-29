#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

void shift(int n, int src, int dest, int aux) {
	if (n == 0) {
		//std::cout << "Transfer Plate " << 1 << " from " << src << " to " << dest << "\n";
		return;
	}
	shift(n - 1, src, aux, dest);
	std::cout << "Transfer Plate " << n << " from " << src << " to " << dest << "\n";
	shift(n - 1, aux, dest, src);
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
	int src = 1, dest = 3, helper = 2;
	shift(n, src, dest, helper);

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}