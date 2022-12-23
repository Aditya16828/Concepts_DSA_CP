#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

using namespace std;

ll power(ll base, ll exp, ll p) { // modular exponentiation
	ll res = 1;
	while (exp) {
		if (exp % 2) res = ((res % p) * (base % p)) % p;
		base = ((base % p) * (base % p)) % p;
		exp = exp / 2;
	}
	return res;
}

ll modInv(ll a, ll p) { //fermat's theorem
	return power(a, p - 2, p);
}

int main()
{
	clock_t begin = clock();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll n, p, ans;
	cin >> n >> p;
	if (n >= p) ans = 0;
	else {
		// (p-1)!%p = ((1.2.3.4.5...n)*(n+1.n+2.n+3...p-1))%p = -1 //wilson therorem
		// n!%p = (-1){((n+1)^-1)%p * ((n+2)^-1)%p * ((n+3)^-1)%p * ... * ((p-1)^-1)%p}.
		ans = 1;
		for (ll i = n + 1; i <= (p - 1); i++) {
			ans = (ans % p * modInv(i, p)) % p;
		}
		ans = -ans;
		cout << (ans + p) % p << "\n";
	}


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}