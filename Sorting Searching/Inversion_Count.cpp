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

ll merge(int start, int mid, int end, std::vector<ll> &arr) {
	ll inv_cnt = 0;
	std::vector<ll> res;
	int i = start, j = mid + 1;
	while (i <= mid and j <= end) {
		if (arr[i] > arr[j]) {
			res.push_back(arr[j]);
			inv_cnt += (mid - i + 1);
			++j;
		} else {
			res.push_back(arr[i]);
			++i;
		}
	}
	while (i <= mid) {
		res.push_back(arr[i]);
		i++;
	}
	while (j <= end) {
		res.push_back(arr[j]);
		j++;
	}
	for (int x = start; x <= end; x++) {
		arr[x] = res[x - start];
	}
	// for (auto &i : res) std::cout << i << ", ";
	// std::cout << "\n";
	return inv_cnt;
}

ll merge_sort(int start, int end, std::vector<ll> &arr) {
	if (start < end) {
		int mid = (start + end) / 2;
		ll inv_left = 0, inv_right = 0, self_inv = 0;
		inv_left = merge_sort(start, mid, arr);
		inv_right = merge_sort(mid + 1, end, arr);
		self_inv = merge(start, mid, end, arr);
		return (inv_left + inv_right + self_inv);
	} else {
		return 0;
	}
}

ll sort(std::vector<ll> &arr) {
	return merge_sort(0, arr.size() - 1, arr);
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		std::vector<ll> arr(n);
		for (int i = 0; i < n; i++) std::cin >> arr[i];
		// for (auto &i : arr) std::cout << i << ", ";
		// std::cout << "\n";
		std::cout << sort(arr) << "\n";
		// for (auto &i : arr) std::cout << i << ", ";
		// std::cout << "\n";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
