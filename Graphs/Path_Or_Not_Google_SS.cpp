// Question ->
// U r Given a grid with directions written on each cel, tell whether it is possible to reach {m-1, n-1} from {0, 0}

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

int n, m;
bool isSafe(int x, int y) {
	return (x >= 0 and y >= 0 and x < n and y < m);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	std::cin >> n >> m;
	vec<vec<char>> grid(n, vec<char>(m));
	loop(i, 0, n - 1) {
		loop(j, 0, m - 1) {
			std::cin >> grid[i][j];
		}
	}

	// Approach: In worst case, we have to read all the cell atleeast once as in each cell direction of travel would be given.
	// So, Time Complexity cannot be reduced; But we can reduce the Space complexity. How??
	// Think that the path length would be max in worst case = m*n.
	// So we can keep a step-counter that would indicate the max number of cell that can be travelled to reach our destination = {n-1, m-1};

	int x = 0, y = 0;
	bool flag = 1;
	loop(counter, 1, (m * n) - 1) {
		if (grid[x][y] == 'U' and isSafe(x - 1, y)) {
			x = x - 1;
		} else if (grid[x][y] == 'D' and isSafe(x + 1, y)) {
			x = x + 1;
		} else if (grid[x][y] == 'L' and isSafe(x, y - 1)) {
			y = y - 1;
		} else if (grid[x][y] == 'R' and isSafe(x, y + 1)) {
			y = y + 1;
		} else {
			flag = 0;
			break;
		}
	}
	if (flag and x == n - 1 and y == m - 1) {
		std::cout << "Possible\n";
	} else std::cout << "Not Possible\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}