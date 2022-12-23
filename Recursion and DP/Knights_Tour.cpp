#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

bool isSafe(std::vector<std::vector<int>> &b, int n, int i, int j) {
	return (i >= 0 and i<n and j >= 0 and j < n and b[i][j] == -1);
}

std::pair<int, int> dir[8] = {std::make_pair(1, 2), std::make_pair(1, -2), std::make_pair(-1, 2), std::make_pair(-1, -2),
                              std::make_pair(2, 1), std::make_pair(2, -1), std::make_pair(-2, 1), std::make_pair(-2, -1)
                             };

bool tour(std::vector<std::vector<int>> &board, int n, int i, int j, int cnt) {
	if (cnt == (n * n)) return true;
	for (int d = 0; d < 8; d++) {
		if (isSafe(board, n, i + dir[d].first, j + dir[d].second)) {
			board[i + dir[d].first][j + dir[d].second] = cnt;
			bool res = tour(board, n, i + dir[d].first, j + dir[d].second, cnt + 1);
			if (res) return true;
			else board[i + dir[d].first][j + dir[d].second] = -1;
		}
	}
	return false;
}

void display(std::vector<std::vector<int>> &board, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << board[i][j] << ", ";
		}
		std::cout << "\n";
	}
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
	std::vector<std::vector<int>> board(n, std::vector<int>(n, -1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = 0;
			bool res = tour(board, n, i, j, 1);
			if (res) display(board, n);
			else std::cout << "No tour for i=" << i << ", j=" << j << "\n";
		}
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}