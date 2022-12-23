// https://www.spoj.com/problems/ADAGCD/
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

ll const max_size = 10000007;
std::vector<ll> pi(max_size, 0);
vll primes;
void gen_pi() {
	loop(i, 0, max_size - 1) {
		pi[i] = i;
	}
	pi[0] = pi[1] = -1;
	for (ll i = 2; i < max_size; i++) {
		if (pi[i] == i) {
			primes.push_back(i);
			// for (ll j = 2 * i; j < max_size; j += i) {
			// 	pi[j] = i;
			// }
		}
		for (ll j = 0; (j < primes.size()) and (primes[j]*i <= max_size - 2) and (primes[j] <= pi[i]); j++) {
			pi[i * primes[j]] = primes[j];
		}
	}
}

ll mod_exp(ll base, ll exp) {
	ll res = 1;
	while (exp--) {
		res *= base;
		res %= mod;
	}
	return res % mod;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	gen_pi();
	ll n;
	std::cin >> n;
	vll gcd(max_size, LLONG_MAX), cnt(max_size, 0);
	ll no = n;
	while (no--) {
		ll m;
		std::cin >> m;

		std::unordered_map<ll, ll> factors;
		while (m--) {
			ll a;
			std::cin >> a;

			// factorisation
			while (a > 1) {
				factors[pi[a]]++;
				a /= pi[a];
			}
		}

		for (auto &el : factors) {
			cnt[el.first]++;
			gcd[el.first] = std::min(gcd[el.first], el.second);
		}
	}
	ll ans = (ll)1;
	for (ll i = 2; i < max_size; i++) {
		if (cnt[i] == n) {
			ans *= (mod_exp(i, gcd[i]) % mod);
			ans %= mod;
		}
	}
	printf("%lld", ans);
	return 0;
}