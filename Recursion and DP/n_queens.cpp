#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

std::vector<std::vector<bool>> board;

bool isSafe(int row, int col, int n) {
	bool x = (row >= 0 and row < n and col >= 0 and col < n);
	bool y = true;
	for (int i = row - 1; i >= 0; i--) {
		if (board[i][col]) {y &= false; break;}
	}
	for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--) {
		if (board[i][j]) {y &= false; break;}
	}
	for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++) {
		if (board[i][j]) {y &= false; break;}
	}
	return (x and y);
}

void print_board(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j]) std::cout << "Q";
			else std::cout << ".";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}
int ways = 0;
void nqueen(int row, int n) {
	if (row == n) {
		print_board(n);
		std::cout << "-------------------------\n";
		ways++;
		return;
	}
	for (int col = 0; col < n; col++) {
		if (isSafe(row, col, n)) {
			board[row][col] = true;
			nqueen(row + 1, n);
			board[row][col] = false;
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
	nqueen(0, n);
	std::cout << "Ways: " << ways;


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}