<<<<<<< HEAD
// https://codeforces.com/problemset/problem/818/E
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

ll const max_size = (ll)(1e5 + 5);
std::bitset<max_size> isPrime;
std::vector<ll> primes;
void gen_primes() {
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (ll i = 2; i < max_size; i++) {
		if (isPrime[i]) {
			for (ll j = 2 * i; j < max_size; j += i) {
				isPrime[j] = false;
			}
		}
	}
	primes.push_back(2);
	for (ll i = 3; i < max_size; i += 2) {
		if (isPrime[i]) primes.push_back(i);
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	gen_primes();
	ll n, k;
	std::cin >> n >> k;
	vll arr(n);
	loop(i, 0, n - 1) std::cin >> arr[i];

	if (k == 1) {
		std::cout << (n * (n + 1)) / 2 << "\n";
	} else {

		std::unordered_map<ll, ll> factors_k;
		for (int i = 0; i < primes.size() and k > 1; i++) {
			ll p = primes[i];
			while (k % p == 0) {
				factors_k[p]++;
				k /= p;
			}
		}

		// for (auto &el : factors_k) std::cout << el.first << "^" << el.second << " * ";
		// std::cout << '\n';

		int i = 0, j = 0;
		ll ans = 0;
		std::unordered_map<ll, ll> factors;
		bool flag = 0;
		while (j < n) {
			if (flag == 0) {
				ll x = arr[j];
				for (int m = 0; m < primes.size() and x > 1; m++) {
					ll p = primes[m];
					while (x % p == 0) {
						factors[p]++;
						x /= p;
					}
				}
			}

			flag = 0;
			for (auto &el : factors_k) {
				if (factors.count(el.first)) {
					if (factors[el.first] >= el.second) flag = 1;
					else flag = 0;
				} else {
					flag = 0;
				}
				if (!flag) break;
			}

			if (flag) {
				ans += (n - j);
				ll temp = arr[i];
				for (int m = 0; m < primes.size() and temp > 1; m++) {
					ll p = primes[m];
					while (temp % p == 0) {
						factors[p]--;
						temp /= p;
					}
				}
				i++;
			} else j++;
		}
		std::cout << ans << "\n";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
=======
// https://codeforces.com/problemset/problem/818/E
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

ll const max_size = (ll)(1e5 + 5);
std::bitset<max_size> isPrime;
std::vector<ll> primes;
void gen_primes() {
	isPrime.set();
	isPrime[0] = isPrime[1] = false;
	for (ll i = 2; i < max_size; i++) {
		if (isPrime[i]) {
			for (ll j = 2 * i; j < max_size; j += i) {
				isPrime[j] = false;
			}
		}
	}
	primes.push_back(2);
	for (ll i = 3; i < max_size; i += 2) {
		if (isPrime[i]) primes.push_back(i);
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	gen_primes();
	ll n, k;
	std::cin >> n >> k;
	vll arr(n);
	loop(i, 0, n - 1) std::cin >> arr[i];

	if (k == 1) {
		std::cout << (n * (n + 1)) / 2 << "\n";
	} else {

		std::unordered_map<ll, ll> factors_k;
		for (int i = 0; i < primes.size() and k > 1; i++) {
			ll p = primes[i];
			while (k % p == 0) {
				factors_k[p]++;
				k /= p;
			}
		}

		// for (auto &el : factors_k) std::cout << el.first << "^" << el.second << " * ";
		// std::cout << '\n';

		int i = 0, j = 0;
		ll ans = 0;
		std::unordered_map<ll, ll> factors;
		bool flag = 0;
		while (j < n) {
			if (flag == 0) {
				ll x = arr[j];
				for (int m = 0; m < primes.size() and x > 1; m++) {
					ll p = primes[m];
					while (x % p == 0) {
						factors[p]++;
						x /= p;
					}
				}
			}

			flag = 0;
			for (auto &el : factors_k) {
				if (factors.count(el.first)) {
					if (factors[el.first] >= el.second) flag = 1;
					else flag = 0;
				} else {
					flag = 0;
				}
				if (!flag) break;
			}

			if (flag) {
				ans += (n - j);
				ll temp = arr[i];
				for (int m = 0; m < primes.size() and temp > 1; m++) {
					ll p = primes[m];
					while (temp % p == 0) {
						factors[p]--;
						temp /= p;
					}
				}
				i++;
			} else j++;
		}
		std::cout << ans << "\n";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
}