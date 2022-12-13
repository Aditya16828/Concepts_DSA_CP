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

std::map<ll, ll> nextSmaller(std::vector<ll> &arr) {
	int n = arr.size();
	std::stack<ll> st; // stores the indexes;
	st.push(n - 1);
	std::map<ll, ll> mp;
	for (int i = 0; i < n; i++)
		mp[arr[i]] = -1;

	for (int i = n - 2; i >= 0; i--) {
		while (not st.empty() and arr[st.top()] > arr[i]) {
			int idx = st.top();
			st.pop();
			mp[arr[idx]] = arr[i];
		}
		st.push(i);
	}
	return mp;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin >> n;
	std::vector<ll> nums(n);
	for (int i = 0; i < n; i++) std::cin >> nums[i];
	std::map<ll, ll> mp = nextSmaller(nums);
	for (auto &el : mp) {
		std::cout << el.first << "-> " << el.second << "\n";
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
