// https://www.spoj.com/problems/GCD2/
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

int gcd(int a, int b) {
	if (b == 0) return a;
	if (a == 0) return b;
	if (b > a) return gcd(b, a);
	else return gcd(b, a % b);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t;
	std::cin >> t;
	while (t--) {
		int a;
		std::string b;
		std::cin >> a;
		std::cin >> b;

		if (a == 0) {
			std::cout << b << "\n";
			continue;
		}
		// since b is very large so instead of find gcd(b, a), we need to find gcd(a, b%a);

		// finding b%a;
		int bmoda = 0;
		int pow = 1;
		for (int i = b.size() - 1; i >= 0; i--) {
			int num = (b[i] - '0');
			bmoda += ((num % a) * pow);
			bmoda %= a;
			pow = ((pow % a) * (10 % a));
			pow %= a;
		}
		std::cout << gcd(a, bmoda) << "\n";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}