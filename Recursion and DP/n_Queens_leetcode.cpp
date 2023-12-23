#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

class Solution {
	std::vector<std::vector<string>> final_result;
	std::vector<std::vector<bool>> board;
	vector<string> convert_board(int n) {
		string s = "";
		vector<string> res;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j]) s += "Q";
				else s += ".";
			}
			res.push_back(s);
			s = "";
		}
		return res;
	}
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
	void nqueen(int row, int n) {
		if (row == n) {
			final_result.push_back(convert_board(n));
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
public:
	vector<vector<string>> solveNQueens(int n) {
		board.resize(n, vector<bool>(n, false));
		nqueen(0, n);
		return final_result;
	}
};

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



#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}