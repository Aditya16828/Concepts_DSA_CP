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

vi primes {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ll bin_exp(ll base, ll exp, ll m) {
	ll res = 1;
	while (exp) {
		if (exp % 2) {
			res = ((res % m) * (base % m)) % m;
		}
		base = ((base % m) * (base % m)) % m;
		exp /= 2;
	}
	return res;
}

bool check_composite(ll a, ll d, ll s, ll n) {
	ll x = bin_exp(a, d, n);
	if (x == 1 or x == (n - 1)) return false;

	for (ll i = 1; i <= s - 1; i++) {
		x = (ll)((x % n) * (x % n)) % n;
		if (x == n - 1) return false;
	}
	return true;
}

bool millerrabin(ll n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n == 3) return true;
	if (n % 2 == 0) return false;

	ll d = n - 1;
	ll s = 0;
	while ((d % 2) == 0) {
		s++;
		d /= 2;
	}
	for (auto a : primes) {
		if (check_composite(a, d, s, n)) {return false;}
	}
	return true;
}

int main(int argc, char const * argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	ll n;
	std::cin >> n;
	std::string ans = millerrabin(n) ? "Is Prime" : "Not Prime";
	std::cout << ans << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
