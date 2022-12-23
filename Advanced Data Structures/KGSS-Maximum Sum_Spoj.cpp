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

ll max2(vll &arr, int start, int end) {
	ll l = -inf, l2 = -inf;
	for (int i = start; i <= end; i++) {
		if (arr[i] > l) {
			l2 = l;
			l = arr[i];
		} else if (arr[i] > l2 and arr[i] != l) {
			l2 = arr[i];
		}
	}
	if (l2 == -inf) l2 = l;
	return l2;
}

void build(std::vector<pllll> &seg, vll &arr, int start, int end, int tidx) {
	// if (end - start + 1 == 2) {
	// 	seg[tidx].first = std::max(arr[start], arr[end]);
	// 	seg[tidx].second = std::min(arr[start], arr[end]);
	// 	return;
	// }

	// if (end - start + 1 == 3) {
	// 	seg[tidx].first = std::max({arr[start], arr[(start + end) / 2], arr[end]});
	// 	seg[tidx].second = max2(arr, start, end);
	// 	return;
	// }
	if (start == end) {
		seg[tidx].first = arr[start];
		seg[tidx].second = -inf;
		return;
	}

	int mid = start + (end - start) / 2;

	build(seg, arr, start, mid, 2 * tidx + 1);
	build(seg, arr, mid + 1, end, 2 * tidx + 2);

	seg[tidx].first = std::max(seg[2 * tidx + 1].first, seg[2 * tidx + 2].first);
	seg[tidx].second = std::max({std::min(seg[2 * tidx + 1].first, seg[2 * tidx + 2].first), seg[2 * tidx + 1].second, seg[2 * tidx + 2].second});
}

void update(std::vector<pllll> &seg, vll &arr, int i, int tidx, int start, int end) {
	if (start == end) {
		seg[tidx].first = arr[start];
		seg[tidx].second = -inf;
		return;
	}

	int mid = start + (end - start) / 2;

	if (i > mid) update(seg, arr, i, 2 * tidx + 2, mid + 1, end);
	else update(seg, arr, i, 2 * tidx + 1, start, mid);

	seg[tidx].first = std::max(seg[2 * tidx + 1].first, seg[2 * tidx + 2].first);
	seg[tidx].second = std::max({std::min(seg[2 * tidx + 1].first, seg[2 * tidx + 2].first), seg[2 * tidx + 1].second, seg[2 * tidx + 2].second});
}

pllll query(std::vector<pllll> &seg, vll &arr, int l, int r, int tidx, int start, int end) {
	if (r < start or end < l) {
		return { -inf, -inf};
	}

	if (start >= l and r >= end) {
		return seg[tidx];
	}

	int mid = start + (end - start) / 2;

	pllll x1 = query(seg, arr, l, r, 2 * tidx + 1, start, mid);
	pllll x2 = query(seg, arr, l, r, 2 * tidx + 2, mid + 1, end);

	ll max1 = std::max(x1.first, x2.first);
	ll max2 = std::max({std::min(x1.first, x2.first), x1.second, x2.second});

	return {max1, max2};
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	ll n;
	std::cin >> n;
	vll arr(n);
	loop(i, 0, n - 1) {
		std::cin >> arr[i];
	}

	std::vector<pllll> seg(4 * n, pllll(-inf, -inf));
	build(seg, arr, 0, n - 1, 0);

	// for (int i = 0; i < 4 * n; i++) {
	// 	std::cout << "{" << seg[i].first << ", " << seg[i].second << "} | ";
	// }

	ll q;
	std::cin >> q;
	while (q--) {
		char type;
		std::cin >> type;
		if (type == 'U') {
			int i, val;
			std::cin >> i >> val;
			i--;
			arr[i] = val;
			update(seg, arr, i, 0, 0, n - 1);
		} else {
			int l, r;
			std::cin >> l >> r;
			l--;
			r--;
			pllll ans = query(seg, arr, l, r, 0, 0, n - 1);
			std::cout << (ans.first + ans.second) << "\n";
			// std::cout << "{" << ans.first << ", " << ans.second << "}\n";
		}
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
