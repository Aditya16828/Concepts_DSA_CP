// https://www.hackerrank.com/challenges/the-power-sum/problem
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

int ways(int x, int n, int num) {
	if (x == 0) return 1;
	if (x < 0) return 0;
	if (pow(num, n) > x) return 0;

	int inc = ways(x - pow(num, n), n, num + 1);
	int exc = ways(x, n, num + 1);

	return inc + exc;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int x, n;
	std::cin >> x >> n;
	std::cout << ways(x, n, 1) << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
