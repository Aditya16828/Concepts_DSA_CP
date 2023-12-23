<<<<<<< HEAD
// https://www.spoj.com/problems/NFACTOR/
=======
// https://www.spoj.com/problems/NFACTOR/
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define inf (long long int)1e18
#define log(args...)    { std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b) for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;
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

vll factors((int)(1e6 + 2), 0);
void gen_factors() {
	for (int i = 2; i <= (int)(1e6); i++) {
		if (factors[i] == 0) {
			for (int j = i; j <= (int)(1e6); j += i) {
				factors[j]++;
			}
		}
	}
}


ll ans[11][(int)(1e6 + 2)];
void gen_ans() {
	gen_factors();
	std::memset(ans, 0, sizeof ans);
	for (int i = 0; i <= 10; i++) {
		for (int j = 1; j <= (int)(1e6); j++) {
			if (factors[j] == i) {ans[i][j] = ans[i][j - 1] + 1;}
			else ans[i][j] = ans[i][j - 1];
		}
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	gen_ans();
	int t;
	std::cin >> t;
	while (t--) {
		ll a, b, n;
		std::cin >> a >> b >> n;
		std::cout << (ans[n][b] - ans[n][a - 1]) << "\n";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
