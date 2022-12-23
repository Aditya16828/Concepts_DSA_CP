// https://leetcode.com/problems/surrounded-regions/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
#define vec std::vector
#define vll std::vector<long long int>
#define vi std::vector<int>
#define vb std::vector<bool>
#define pii std::pair<int, int>
#define pllll std::pair<long long int, long long int>
#define loop(i, a, b) for(int i=a;i<=b;i++)
#define rloop(i, a, b) for(int i=a;i>=b;i--)
#define iter_all(el, cont) for(auto &el:cont)

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

class Solution {
	std::pair<int, int> d[4] = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
	bool isSafe(int i , int j, vector<vector<char>>& board) {
		return (i >= 0 and j >= 0 and i < board.size() and j < board[0].size());
	}
	void dfs(int i, int j, std::vector<std::vector<bool>> &vis, vector<vector<char>>& board) {
		vis[i][j] = true;
		for (int x = 0; x < 4; x++) {
			if (isSafe(i + d[x].first, j + d[x].second, board) and !vis[i + d[x].first][j + d[x].second] and board[i + d[x].first][j + d[x].second] == 'O') {
				dfs(i + d[x].first, j + d[x].second, vis, board);
			}
		}
	}
public:
	void solve(vector<vector<char>>& board) {
		int m = board.size();
		int n = board[0].size();

		std::vector<std::vector<bool>> vis(m, std::vector<bool>(n, false));
		std::vector<std::vector<char>> res(m, std::vector<char>(n, 'X'));

		for (int j = 0; j < n; j++) { // top row
			if (isSafe(0, j, board) and !vis[0][j] and board[0][j] == 'O') {
				dfs(0, j, vis, board);
			}
		}
		for (int j = 0; j < n; j++) { // bottom row
			if (isSafe(m - 1, j, board) and !vis[m - 1][j] and board[m - 1][j] == 'O') {
				dfs(m - 1, j, vis, board);
			}
		}
		for (int i = 0; i < m; i++) { // left col
			if (isSafe(i, 0, board) and !vis[i][0] and board[i][0] == 'O') {
				dfs(i, 0, vis, board);
			}
		}
		for (int i = 0; i < m; i++) { // right col
			if (isSafe(i, n - 1, board) and !vis[i][n - 1] and board[i][n - 1] == 'O') {
				dfs(i, n - 1, vis, board);
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i][j]) board[i][j] = 'O';
				else board[i][j] = 'X';
			}
		}
		// return res;
	}
};

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....



#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}