/*
Given an array of size n and an integer d. Find a subarray with length atleast d,
such that average of elements of this subarray is max possible.
*/
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

std::vector<double> prefixSum(std::vector<int> &arr, double avg) {
	std::vector<double> v;
	int n = arr.size();
	for (int i = 0; i < n; i++)
		v.push_back(arr[i] - avg);
	for (int i = 1; i < n; i++) {
		v[i] += v[i - 1];
	}
	return v;
}

std::vector<double> prefixMin(std::vector<double> arr) {
	int n = arr.size();
	for (int i = 1; i < n; i++) {
		arr[i] = std::min(arr[i], arr[i - 1]);
	}
	return arr;
}

bool possible(double avg, std::vector<int> &arr, int d) {
	std::vector<double> prefix_sum = prefixSum(arr, avg);
	std::vector<double> prefix_min = prefixMin(prefix_sum);

	int n = arr.size();
	for (int r = d; r < n; r++) {
		int l = r - d;
		if (prefix_min[l] <= prefix_sum[r])
			return true;
	}
	return false;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n, d;
	std::cin >> n >> d;
	std::vector<int> arr(n);
	for (int i = 0; i < n; i++) std::cin >> arr[i];
	double lo = 0, hi = *(std::max_element(arr.begin(), arr.end())), ans = -1;
	for (int i = 0; i < 150; i++) {
		double mid = lo + (hi - lo) / 2;
		if (possible(mid, arr, d)) {
			ans = mid;
			lo = mid;
		} else {
			hi = mid;
		}
	}
	std::cout << std::fixed << std::setprecision(6) << ans << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
