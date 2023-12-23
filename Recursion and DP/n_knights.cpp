#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

std::vector<std::vector<bool>> board;
int ways = 0;

bool isValid(int row, int col, int n) {
	return row >= 0 and row < n and col >= 0 and col < n;
}

bool isSafe(int row, int col, int n) {
	std::vector<int> dx = { -2, -2,  -1, -1};
	std::vector<int> dy = {1, -1, -2, 2};
	for (int i = 0; i < 4; i++) {
		if (isValid(row + dx[i], col + dy[i], n) and board[row + dx[i]][col + dy[i]])
			return false;
	}
	return true;
}

void print_board(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j]) std::cout << "K";
			else std::cout << ".";
		}
		std::cout << "\n";
	}
	std::cout << "\n------------------------------\n";
}

void nknights(int sr, int sc, int count, int n) {
	if (count == n) {
		print_board(n);
		++ways;
		return;
	}
	for (int j = sc; j < n; j++) {
		if (isSafe(sr, j, n) and not board[sr][j]) {
			board[sr][j] = true;
			nknights(sr, j + 1, count + 1, n);
			board[sr][j] = false;
		}
	}
	for (int i = sr + 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (isSafe(i, j, n) and not board[i][j]) {
				board[i][j] = true;
				nknights(i, j + 1, count + 1, n);
				board[i][j] = false;
			}
		}
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
	board.resize(n, std::vector<bool>(n, false));
	nknights(0, 0, 0, n);
	std::cout << "Ways: " << ways;

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}