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

vec<vll> multiply(vec<vll> &a, vec<vll> &b, int order) {
	vec<vll> res(order, vll(order, 0));
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			for (int k = 0; k < order; k++) {
				res[i][j] = (res[i][j] % mod) + ((a[i][k] * b[k][j]) % mod);
				res[i][j] %= mod;
			}
		}
	}
	return res;
}

vec<vll> expo(vec<vll> mat, int p) {
	int order = mat.size();
	vec<vll> res {{1, 0}, {0, 1}};
	while (p) {
		if (p % 2) {
			res = multiply(res, mat, order);
		}
		mat = multiply(mat, mat, order);
		p /= 2;
	}
	return res;
}

ll fibo(ll n) {
	if (n == 0 or n == 1) return n;
	vec<vll> tm = {{0, 1}, {1, 1}};
	tm = expo(tm, n - 1);
	return tm[1][0] * 0 + tm[1][1] * 1;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	// vec<vll> m = {{0, 1}, {1, 1}};
	// m = expo(m, 2);
	// iter_all(el, m) {
	// 	iter_all(i, el) {
	// 		std::cout << i << ", ";
	// 	}
	// 	std::cout << "\n";
	// }
	int n;
	std::cin >> n;
	loop(i, 0, n) std::cout << fibo(i) << ", ";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}