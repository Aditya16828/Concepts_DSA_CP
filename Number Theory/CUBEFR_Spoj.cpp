// https://www.spoj.com/problems/CUBEFR/
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

std::map<ll, ll> ans;
std::bitset<1000005> iscbfree;
void gen_set() {
	iscbfree.set();
	iscbfree[0] = 0;
	for (int i = 2; i * i * i <= 1000001; i++) {
		for (ll j = 1; j * (i * i * i) <= 1000001; j++) {
			iscbfree[i * i * i * j] = 0;
		}
	}
	ll pos = 1;
	loop(i, 1, 1000001) {
		if (iscbfree[i]) {ans[i] = pos; ++pos;}
		else ans[i] = -1;
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	gen_set();
	int t;
	std::cin >> t;
	loop(i, 1, t) {
		int n;
		std::cin >> n;
		if (ans[n] > -1) std::cout << "Case " << i << ": " << ans[n] << "\n";
		else std::cout << "Case " << i << ": Not Cube Free" << "\n";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
