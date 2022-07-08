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
	if (start ==  end) {
		seg[tidx] = arr[start];
		return;
	}

	int mid = start + (end - start) / 2;

	build(seg, arr, start, mid, 2 * tidx + 1);
	build(seg, arr, mid + 1, end, 2 * tidx + 2);

	seg[tidx] = std::max(seg[2 * tidx + 1], seg[2 * tidx + 2]);
}

void update(vi &seg, vi &arr, int start, int end, int tidx, int i) {
	if (start == end) {
		seg[tidx] = arr[i];
		return;
	}

	int mid = start + (end - start) / 2;

	if (i > mid) {
		update(seg, arr, mid + 1, end, 2 * tidx + 2, i);
	} else {
		update(seg, arr, start, mid, 2 * tidx + 1, i);
	}

	seg[tidx] = std::max(seg[2 * tidx + 1], seg[2 * tidx + 2]);
}

int query(vi &seg, vi &arr, int start, int end, int tidx, int l, int r, int x) {
	if (end < l or start > r) {
		return INT_MAX;
	}
	if (start == end) {
		if (seg[tidx] < x) return INT_MAX;
		else return seg[tidx];
	}

	int mid = start + (end - start) / 2;

	int lst = query(seg, arr, start, mid, 2 * tidx + 1, l, r, x);
	int rst = query(seg, arr, mid + 1, end, 2 * tidx + 2, l, r, x);

	return std::min(lst, rst);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin >> n;
	vi arr(n);
	loop(i, 0, n - 1) std::cin >> arr[i];

	vi seg(4 * n, INT_MIN);
	build(seg, arr, 0, n - 1, 0);

	int q;
	std::cin >> q;
	while (q--) {
		int type;
		std::cin >> type;
		if (type == 1) {
			int i, val;
			std::cin >> i >> val;
			arr[i] = val;
			update(seg, arr, 0, n - 1, 0, i);
		}
		if (type == 2) {
			int l, r, x;
			std::cin >> l >> r >> x;
			int ans = query(seg, arr, 0, n - 1, 0, l, r, x);
			std::cout << ans << "\n";
		}
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}