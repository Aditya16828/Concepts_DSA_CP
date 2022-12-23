/*
Given an array of n integers and q queries. In each query u r given 3 values (i, j , k). For each query return the number of elements greater than k in the subseq a[i], a[i+1], a[i+2], ...., a[j]
n <= 3e4
a[i] <= 1e9
q <= 2e5
u will be given (a, b, c), find out (i, j, k) by
	i = a ^ lastans
	j = b ^ lastans
	k = c ^ lastans
initially, lastans = 0.

Approach: If the array in range [i, j] is sorted ten it can be easily found by using upper_bound(val) {-> returns iterator to the element > val.}
	So store a sorted vector from [start, end] in each node of the segment tree.
*/
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

int upper_bound(vi &arr, int key) {
	int hi = arr.size() - 1, lo = 0;
	int ans = -1;
	while (lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if (arr[mid] > key) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}
	return ans;
}

int count(vi &arr, int key) {
	if (upper_bound(arr, key) > -1)
		return (arr.size() - upper_bound(arr, key));
	else return 0;
}

void build(vec<vi> &seg, vi &arr, int start, int end, int tidx) {
	if (start == end) {
		seg[tidx].push_back(arr[start]);
		return;
	}

	int mid = start + (end - start) / 2;

	build(seg, arr, start, mid, 2 * tidx + 1);
	build(seg, arr, mid + 1, end, 2 * tidx + 2);

	// merging 2 sorted arrays
	int i = 0, j = 0;
	while (i < seg[2 * tidx + 1].size() and j < seg[2 * tidx + 2].size()) {
		if (seg[2 * tidx + 1][i] < seg[2 * tidx + 2][j]) {
			seg[tidx].push_back(seg[2 * tidx + 1][i]);
			i++;
		} else {
			seg[tidx].push_back(seg[2 * tidx + 2][j]);
			j++;
		}
	}
	while (i < seg[2 * tidx + 1].size()) {
		seg[tidx].push_back(seg[2 * tidx + 1][i]);
		i++;
	}
	while (j < seg[2 * tidx + 2].size()) {
		seg[tidx].push_back(seg[2 * tidx + 2][j]);
		j++;
	}
}

int query(vec<vi> &seg, vi &arr, int start, int end, int tidx, int l, int r, int k) {
	if (end < l or start > r) return 0;
	if (start >= l and r >= end) {
		return count(seg[tidx], k);
	}

	int mid = start + (end - start) / 2;

	int lst = query(seg, arr, start, mid, 2 * tidx + 1, l, r, k);
	int rst = query(seg, arr, mid + 1, end, 2 * tidx + 2, l, r, k);

	return (lst + rst);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin >> n;
	vi arr(n);
	loop(i, 0, n - 1) std::cin >> arr[i];

	vec<vi> seg(4 * n, vi());
	build(seg, arr, 0, n - 1, 0);
	// iter_all(el, seg[0]) std::cout << el << ", ";
	// std::cout << "\n";

	int q;
	std::cin >> q;
	int lastans = 0;
	while (q--) {
		int a, b, c;
		std::cin >> a >> b >> c;
		int i = a ^ lastans;
		int j = b ^ lastans;
		int k = c ^ lastans;
		std::cout << i << ", " << j << ", " << k << "\n";
		lastans = query(seg, arr, 0, n - 1, 0, i, j, k);
		std::cout << lastans << "\n";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}