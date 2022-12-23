// https://practice.geeksforgeeks.org/problems/help-the-old-man3848/1#
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

using namespace std;

class Solution {
	vector<pair<int, int>> res;
	int moves;
public:
	Solution() {
		moves = 0;
	}
	void shift(int n, int src, int dest, int helper) {
		if (n == 0) return;
		shift(n - 1, src, helper, dest);
		res.push_back(make_pair(src, dest));
		shift(n - 1, helper, dest, src);
	}
	vector<int> shiftPile(int N, int n) {
		shift(N, 1, 3, 2);
		vector<int> x = {res[n - 1].first, res[n - 1].second};
		return x;
	}
};

int main()
{
	clock_t begin = clock();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int N, n;
		cin >> N >> n;

		Solution ob;
		vector<int> ans = ob.shiftPile(N, n);
		cout << ans[0] << " " << ans[1] << endl;
	}
	return 0;

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}