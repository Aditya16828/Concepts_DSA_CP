#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

std::vector<std::vector<bool>> board;
std::bitset<20> col, left_d, rt_d;
int ways = 0;

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

void nqueens(int i, int n) {
	if (i == n) {
		++ways;
		print_board(n);
		std::cout << "-----------------\n";
		return;
	}
	for (int j = 0; j < n; j++) {
		if ((not col[j]) and (not rt_d[i + j]) and (not left_d[i - j + n - 1])) {
			col[j] = rt_d[i + j] = left_d[i - j + n - 1] = true;
			board[i][j] = true;
			nqueens(i + 1, n);
			board[i][j] = false;
			col[j] = rt_d[i + j] = left_d[i - j + n - 1] = false;
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

	col.reset();
	left_d.reset();
	rt_d.reset();
	int n;
	std::cin >> n;
	board.resize(n, std::vector<bool>(n, false));
	nqueens(0, n);
	std::cout << ways;

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}