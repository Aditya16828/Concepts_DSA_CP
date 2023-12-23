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

bool isSafe(int row, int col, std::vector<std::vector<char>> &grid){
	return (row >= 0 and col >= 0 and grid[row][col] != '#');
}

int paths(int i, int j, std::vector<std::vector<char>> &grid, std::vector<std::vector<int>> &dp){
	if(i == 0 and j == 0) return 1;
	if(!isSafe(i, j, grid)) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	int up = paths(i-1, j, grid, dp);
	int left = paths(i, j-1, grid, dp);

	return dp[i][j] = (up%mod+left%mod)%mod;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int h, w;
	std::cin>>h>>w;
	std::vector<std::vector<char>> grid(h, std::vector<char>(w, '.'));
	for(int i=0;i<h;i++){
		std::string s;
		std::cin>>s;
		for(int j=0;j<s.size();j++){
			grid[i][j] = s[j];
		}
	}

	std::vector<std::vector<int>> dp(h, std::vector<int>(w, 0));

	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(i == 0 and j == 0) dp[i][j] = 1;
			else {
				int up = 0, left = 0;
				if(!isSafe(i, j, grid)){dp[i][j] = 0;}
				else{
					if(i > 0) up = dp[i-1][j];
					if(j > 0) left = dp[i][j-1];
					dp[i][j] = (up%mod + left%mod)%mod;
				}
			}
		}
	}

	// std::cout<<paths(h-1, w-1, grid, dp);
	std::cout<<dp[h-1][w-1];

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}