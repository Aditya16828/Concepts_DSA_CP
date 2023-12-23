// https://www.spoj.com/problems/SEQ/
#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000000
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
				res[i][j] = (res[i][j] + (((a[i][k]) * (b[k][j])) % mod)) % mod;
			}
		}
	}
	return res;
}

vec<vll> expo(vec<vll> mat, int p) {
	int order = mat.size();
	vec<vll> res(order, vll(order, 0));
	for (int i = 0; i < order; i++) res[i][i] = 1;
	while (p) {
		if (p % 2) res = multiply(res, mat, order);
		mat = multiply(mat, mat, order);
		p /= 2;
	}
	return res;
}

ll Tn(ll n, vll &coeff, vll &T0) {
	int order = T0.size();
	for (int i = 0; i < order; i++) {
		if (n - 1 == i) return T0[i];
	}
	vec<vll> tm(order, vll(order, 0));
	for (int i = 0, j = 1; i <= order - 2 and j <= order - 1; i++, j++) {
		tm[i][j] = 1;
	}
	for (int i = 0; i < order; i++) {
		tm[order - 1][i] = coeff[order - 1 - i];
	}
	// iter_all(el, tm){
	//     iter_all(i, el) std::cout<<i<<", ";
	//     std::cout<<"\n";
	// }

	ll res = 0;
	tm = expo(tm, n - order);
	for (int i = 0; i < order; i++) {
		res = (res % mod + ((tm[order - 1][i] * T0[i]) % mod)) % mod;
	}
	return res;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t;
	std::cin >> t;
	while (t--) {
		int k;
		std::cin >> k;
		vll T0(k);
		loop(i, 0, k - 1) std::cin >> T0[i];
		vll coeff(k);
		loop(i, 0, k - 1) std::cin >> coeff[i];
		ll n;
		std::cin >> n;
		std::cout << Tn(n, coeff, T0) << "\n";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}