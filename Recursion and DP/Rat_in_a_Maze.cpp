// https://www.codechef.com/problems/BPHC03

#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

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

bool isSafe(std::vector<std::vector<int>> &maze, std::vector<std::vector<bool>>&vis, int row, int col) {
	int n = maze.size();
	return (row >= 0 and col >= 0 and row < n and col < n and (not vis[row][col]) and (maze[row][col] == 0));
}

int ways;
void compute(std::vector<std::vector<int>> &maze, std::vector<std::vector<bool>>&vis, int row, int col) {
	int n = maze.size();
	if (row == n - 1 and col == n - 1) {
		++ways;
		return;
	}
	vis[row][col] = true;
	if (isSafe(maze, vis, row + 1, col)) {compute(maze, vis, row + 1, col);}
	if (isSafe(maze, vis, row - 1, col)) {compute(maze, vis, row - 1, col);}
	if (isSafe(maze, vis, row, col + 1)) {compute(maze, vis, row, col + 1);}
	if (isSafe(maze, vis, row, col - 1)) {compute(maze, vis, row, col - 1);}
	vis[row][col] = false;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin >> n;
	std::vector<std::vector<int>> maze(n, std::vector<int>(n));
	std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			std::cin >> maze[i][j];
	}
	compute(maze, visited, 0, 0);
	std::cout << ways << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
