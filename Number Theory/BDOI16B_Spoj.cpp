// https://www.spoj.com/problems/BDOI16B/
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

int max_size = (int)(1e5 + 2);
vll pi(max_size);
vll primes;
void gen_primes() {
	loop(i, 0, max_size - 2) pi[i] = i;
	pi[1] = -1;
	for (int i = 2; i <= max_size - 2; i++) {
		if (pi[i] == i) primes.push_back(i);
		// we will go to each prime number in the prime array which are less than pi[i].
		for (int j = 0; (j < primes.size()) and (primes[j] <= pi[i]) and ((i * primes[j]) <= (max_size - 2)); j++) {
			pi[i * primes[j]] = primes[j];
		}
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	gen_primes();
	int t;
	std::cin >> t;
	loop(i, 1, t) {
		ll n, k;
		std::cin >> n >> k;

		// prime factorisation of n!
		ll ans = inf;
		ll x = k;
		for (int i = 0; i < primes.size(); i++) {
			ll p = primes[i];
			ll cnt1 = 0;
			while (n / p) {
				cnt1 += (n / p);
				p *= primes[i];
			}
			if (cnt1 == 0) continue;

			ll cnt2 = 0;
			while (x % primes[i] == 0) {
				cnt2++;
				x = x / primes[i];
			}

			if (cnt2) ans = std::min(ans, cnt1 / cnt2);
		}

		// ??
		if (x > 1) {
			ll p = x;
			ll cnt = 0;
			while (n / p) {
				cnt += (n / p);
				p *= x;
			}
			ans = std::min(ans, cnt);
		}

		if (ans == inf) ans = 0;

		std::cout << "Case " << i << ": " << ans << "\n";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
