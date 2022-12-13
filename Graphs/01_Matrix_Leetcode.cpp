// https://leetcode.com/problems/01-matrix/submissions/
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
	bool isSafe(int x, int y, int m, int n) {
		return (x >= 0 and y >= 0 and x < m and y < n);
	}
public:
	// take the zeros as each src and push them in the queue, then calculate the min distances from 0's to the 1's
	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		queue<pair<int, int>> q;
		int m = mat.size();
		int n = mat[0].size();

		vector<vector<int>> res(m, vector<int>(n, INT_MAX));

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!mat[i][j]) {
					res[i][j] = 0;
					q.push({i, j});
				}
			}
		}

		while (!q.empty()) {
			pair<int, int> curr = q.front();
			q.pop();

			int i = curr.first;
			int j = curr.second;

			if (isSafe(i + 1, j, m, n)) {
				if (res[i + 1][j] > res[i][j] + 1) {
					res[i + 1][j] = res[i][j] + 1;
					q.push({i + 1, j});
				}
			}
			if (isSafe(i - 1, j, m, n)) {
				if (res[i - 1][j] > res[i][j] + 1) {
					res[i - 1][j] = res[i][j] + 1;
					q.push({i - 1, j});
				}
			}
			if (isSafe(i, j + 1, m, n)) {
				if (res[i][j + 1] > res[i][j] + 1) {
					res[i][j + 1] = res[i][j] + 1;
					q.push({i, j + 1});
				}
			}
			if (isSafe(i, j - 1, m, n)) {
				if (res[i][j - 1] > res[i][j] + 1) {
					res[i][j - 1] = res[i][j] + 1;
					q.push({i, j - 1});
				}
			}
		}
		return res;
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