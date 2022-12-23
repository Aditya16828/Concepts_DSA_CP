#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define log(args...) 	{ std::string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); std::stringstream _ss(_s); std::istream_iterator<std::string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) std::cout<<(arr[z])<<" ";std::cout<<std::endl;

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

bool possible(double max_time, std::vector<int> x, std::vector<int> v) {
	double max_x = INT64_MAX, min_x = INT64_MIN;
	int n = x.size();
	for (int i = 0; i < n; i++) {
		max_x = std::min(max_x, (x[i] + (max_time * v[i])));
		min_x = std::max(min_x, (x[i] - (max_time * v[i])));
	}
	return (min_x <= max_x);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin >> n;
	std::vector<int> x(n), v(n);
	for (int i = 0; i < n; i++) std::cin >> x[i];
	for (int i = 0; i < n; i++) std::cin >> v[i];
	double lo = 0, hi = 10000000000.0, ans = -1;
	for (int i = 0; i < 150; i++) {
		double mid = lo + (hi - lo) / 2;
		if (possible(mid, x, v)) {
			ans = mid;
			hi = mid;
		} else {
			lo = mid;
		}
	}
	std::cout << std::fixed << std::setprecision(6) << ans << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
