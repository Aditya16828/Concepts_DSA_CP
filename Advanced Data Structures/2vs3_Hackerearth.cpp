// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/2-vs-3/
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

void build(vec<pllll> &seg, vec<char> &arr, int start, int end, int tidx) {
	if (start == end) {
		seg[tidx].first = 1;
		seg[tidx].second = arr[start] - '0';
		return;
	}

	int mid = start + (end - start) / 2;

	build(seg, arr, start, mid, 2 * tidx + 1);
	build(seg, arr, mid + 1, end, 2 * tidx + 2);

	seg[tidx].first = seg[2 * tidx + 1].first + seg[2 * tidx + 2].first;
	seg[tidx].second = ((((ll)pow(2, seg[2 * tidx + 2].first) % 3) * seg[2 * tidx + 1].second ) % 3) + (seg[2 * tidx + 2].second % 3);
	seg[tidx].second %= 3;
}

pii query(vec<pllll> &seg, vec<char> &arr, int start, int end, int tidx, int l, int r) {
	if (r < start or end < l) {
		return {0, 0};
	}
	if (start >= l and end <= r) {
		return seg[tidx];
	}

	int mid = start + (end - start) / 2;

	pii lst = query(seg, arr, start, mid, 2 * tidx + 1, l, r);
	pii rst = query(seg, arr, mid + 1, end, 2 * tidx + 2, l, r);

	pllll temp = {0, 0};
	temp.first = lst.first + rst.first;
	temp.second = ((((ll)pow(2, rst.first) % 3) * lst.second) % 3) + (rst.second % 3);
	return temp;
}

void update(vec<pllll> &seg, vec<char> &arr, int start, int end, int tidx, int i) {
	if (start == end) {
		seg[tidx].first = 1;
		seg[tidx].second = arr[i] - '0';
		return;
	}

	int mid = start + (end - start) / 2;

	if (i > mid) {
		update(seg, arr, mid + 1, end, 2 * tidx + 2, i);
	} else {
		update(seg, arr, start, mid, 2 * tidx + 1, i);
	}

	seg[tidx].first = seg[2 * tidx + 1].first + seg[2 * tidx + 2].first;
	seg[tidx].second = ((((ll)pow(2, seg[2 * tidx + 2].first) % 3) * seg[2 * tidx + 1].second) % 3) + (seg[2 * tidx + 2].second % 3);
	seg[tidx].second %= 3;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin >> n;
	std::string bin;
	std::cin >> bin;

	std::vector<char> str(bin.begin(), bin.end());
	// for (auto &i : str) std::cout << i;
	// std::cout << "\n";
	std::vector<pllll> seg(4 * n, std::pair<int, int>(0, 0));
	build(seg, str, 0, n - 1, 0);
	// for (auto &i : seg) std::cout << "{" << i.first << ", " << i.second << "}; ";

	int q;
	std::cin >> q;
	while (q--) {
		int type;
		std::cin >> type;
		if (type == 0) {
			// query
			int l, r;
			std::cin >> l >> r;
			pii ans = query(seg, str, 0, n - 1, 0, l, r);
			std::cout << (ans.second % 3) << "\n";
		} else {
			// update
			int idx;
			std::cin >> idx;
			if (str[idx] == '0') {
				str[idx] = '1';
				update(seg, str, 0, n - 1, 0, idx);
			}
		}
	}


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
