/*
Given an array of binary values {0, 1};
You need to support 2 different types of queries:
1. set(i, v) -> arr[i] = v;
2. find(k) -> returns the index of kth one.

Approach:
	Store the number of ones [start, end] in the nodes. If number of ones in lst >= k then go to lst;
	otherwise go to rst with k-val[lst] number of ones.
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

void build(vi &seg, vi &arr, int start, int end, int tidx) {
	if (start == end) {
		if (arr[start]) seg[tidx] = 1;
		else seg[tidx] = 0;
		return;
	}

	int mid = start + (end - start) / 2;

	build(seg, arr, start, mid, 2 * tidx + 1);
	build(seg, arr, mid + 1, end, 2 * tidx + 2);

	seg[tidx] = seg[2 * tidx + 1] + seg[2 * tidx + 2];
}

void update(vi &seg, vi &arr, int start, int end, int tidx, int i) {
	if (start == end) {
		seg[tidx] = arr[i];
		return;
	}

	int mid = start + (end - start) / 2;

	if (i > mid) update(seg, arr, mid + 1, end, 2 * tidx + 2, i);
	else update(seg, arr, start, mid, 2 * tidx + 1, i);

	seg[tidx] = seg[2 * tidx + 1] + seg[2 * tidx + 2];
}

int query(vi &seg, vi &arr, int start, int end, int tidx, int k) {
	if (seg[tidx] < k) return -1;

	if (start == end) return start;

	int mid = start + (end - start) / 2;

	if (seg[2 * tidx + 1] >= k) {
		return query(seg, arr, start, mid, 2 * tidx + 1, k);
	} else {
		return query(seg, arr, mid + 1, end, 2 * tidx + 2, k - seg[2 * tidx + 1]);
	}
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin >> n;
	vi arr(n);
	loop(i, 0, n - 1) {
		std::cin >> arr[i];
	}

	vi seg(4 * n, -1);
	build(seg, arr, 0, n - 1, 0);
	// iter_all(el, seg) std::cout << el << ", ";
	// std::cout << "\n";

	int q;
	std::cin >> q;
	while (q--) {
		int type;
		std::cin >> type;
		if (type == 1) {
			int i, v;
			std::cin >> i >> v;
			arr[i] = v;
			update(seg, arr, 0, n - 1, 0, i);
		} else {
			int k;
			std::cin >> k;
			std::cout << query(seg, arr, 0, n - 1, 0, k) << "\n";
		}
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}