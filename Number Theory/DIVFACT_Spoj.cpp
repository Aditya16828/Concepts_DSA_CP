// https://www.spoj.com/problems/DIVFACT/
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

std::bitset<50002> isPrimes;
std::vector<ll> primes;
void gen_primes() {
	isPrimes.set();
	isPrimes[0] = isPrimes[1] = false;
	for (ll i = 2; i * i <= 50002; i++) {
		if (isPrimes[i]) {
			for (ll j = 2 * i; j < 50002; j += i) {
				isPrimes[j] = false;
			}
		}
	}
	primes.push_back(2);
	loop(i, 3, 50001) {
		if (isPrimes[i]) primes.push_back(i);
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	gen_primes();
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		ll ans = 1;
		for (ll i = 0; primes[i] <= n; i++) {
			ll p = primes[i];
			ll count = 0;
			while (n / p) {
				count += (n / p);
				p = p * primes[i];
			}
			ans *= ((count + 1) % mod);
			ans %= mod;
		}
		std::cout << ans << "\n";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}