// https://codeforces.com/contest/1244/problem/C
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

struct data {
	ll gcd, x, y;
};

data gcd_extd(ll a, ll b) {
	if (b == 0) {
		data res;
		res.gcd = a;
		res.x = a;
		res.y = 0;
		return res;
	}

	data temp = gcd_extd(b, a % b);
	data res;
	res.gcd = temp.gcd;
	res.x = temp.y;
	res.y = (temp.x - (a / b) * temp.y);
	return res;
}

ll modInv(ll a, ll m) {
	data d = gcd_extd(a, m);
	return (d.x + m) % m;
}

pllll solution(ll a, ll b, ll c) {
	data t = gcd_extd(a, b);
	if (c % t.gcd) {
		return { -1, -1};
	}
	a /= t.gcd;
	b /= t.gcd;
	c /= t.gcd;
	ll y0 = ((c % a) * modInv(b, a) % a);
	ll x0 = (c - b * y0) / a;
	if (x0 < 0 or y0 < 0) return { -1, -1};
	return {x0, y0};
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	ll n, p, w, d;
	std::cin >> n >> p >> w >> d;
	pllll ans = solution(w, d, p);
	ll x = ans.first;
	ll y = ans.second;
	if (x == -1 and y == -1) {
		std::cout << "-1\n";
	} else {
		ll z = n - (x + y);
		if (z < 0) {
			std::cout << "-1\n";
		} else {
			std::cout << x << " " << y << " " << z << "\n";
		}
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
