// https://www.lintcode.com/problem/android-unlock-patterns/description
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

int via[10][10];
int helper(std::vector<bool> &vis, int curr, int rem) {
	if (rem == 0) return 1;
	vis[curr] = true;
	int res = 0;
	for (int i = 1; i <= 9; i++) {
		if (not vis[i] and (via[curr][i] == 0 or vis[via[curr][i]])) {
			res += helper(vis, i, rem - 1);
		}
	}
	vis[curr] = false;
	return res;
}
int numberOfPatterns(int m, int n) {
	memset(via, 0, sizeof(via));
	via[1][3] = via[3][1] = 2;
	via[1][7] = via[7][1] = 4;
	via[9][3] = via[3][9] = 6;
	via[9][7] = via[7][9] = 8;
	via[1][9] = via[9][1] = via[7][3] = via[3][7] = via[2][8] = via[8][2] = via[4][6] = via[6][4] = 5;
	int ways = 0;
	std::vector<bool> visited(10, false);
	for (int i = m; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			ways += helper(visited, j, i - 1);
		}
	}
	return ways;
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

	int m, n;
	std::cin >> m >> n;
	std::cout << numberOfPatterns(m, n) << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}