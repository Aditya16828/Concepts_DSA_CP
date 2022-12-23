// https://www.codechef.com/problems-old/GCDQ
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

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t, n, q, x, l, r;
	vector<int> a, prefix_gcd, suffix_gcd;
	cin >> t;
	while (t--)
	{
		cin >> n >> q;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			a.push_back(x);
		}

		prefix_gcd.push_back(a[0]);

		for (int i = 1; i < n; i++)
		{
			prefix_gcd.push_back(__gcd(prefix_gcd[i - 1], a[i]));
		}

		suffix_gcd.resize(n);
		suffix_gcd[n - 1] = a[n - 1];

		for (int i = n - 2; i >= 0; i--)
		{
			suffix_gcd[i] = __gcd(suffix_gcd[i + 1], a[i]);
		}

		while (q--)
		{
			cin >> l >> r;
			if (l - 2 < 0)
				cout << suffix_gcd[r] << endl;
			else if (r >= n)
				cout << prefix_gcd[l - 2] << endl;
			else
				cout << __gcd(prefix_gcd[l - 2], suffix_gcd[r]) << endl;
		}
		a.clear();
		suffix_gcd.clear();
		prefix_gcd.clear();
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}