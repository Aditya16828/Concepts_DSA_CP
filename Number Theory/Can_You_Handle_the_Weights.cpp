// https://www.hackerearth.com/problem/algorithm/can-you-handle-the-weights/
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
	ll x, y, gcd;
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
	data ans;
	ans.gcd = temp.gcd;
	ans.x = temp.y;
	ans.y = (temp.x - ((a / b) * temp.y));
	return ans;
}

ll modInv(ll a, ll m) {
	data t = gcd_extd(a, m);
	return (t.x + m) % m;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	// ax + by = d -> Linear Diophantine equation
	int t;
	std::cin >> t;
	while (t--) {
		ll a, b, d;
		std::cin >> a >> b >> d;
		data t = gcd_extd(a, b);
		if (d % t.gcd) {
			std::cout << "0\n";
		} else if (d == 0) {
			std::cout << "1\n";
		} else {
			// reduce into siplified form
			d /= t.gcd;
			a /= t.gcd;
			b /= t.gcd;

			ll y1 = ((d % a) * modInv(b, a)) % a; // first value of y for which the equation is satisfied
			if (y1 * b > d) std::cout << "0\n";
			else {
				std::cout << (((d / b) - y1) / a) + 1 << "\n";
			}
		}
	}


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
