// https://www.spoj.com/problems/MCOINS/
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

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	std::vector<bool> dp(1000005); // return whether i is a loosing state or winning state
	int K, L, m;
	std::cin >> K >> L >> m;

	dp[1] = dp[K] = dp[L] = true;
	for (int i = 2; i <= 1000001; i++) {
		dp[i] = dp[i - 1];
		if (i >= K) {
			dp[i] = dp[i] and dp[i - K];
		}
		if (i >= L) {
			dp[i] = dp[i] and dp[i - L];
		}
		dp[i] = not dp[i];
	}

	for (int i = 0; i < m; i++) {
		int n;
		std::cin >> n;
		if (dp[n]) std::cout << "A";
		else std::cout << "B";
	}
	std::cout << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
