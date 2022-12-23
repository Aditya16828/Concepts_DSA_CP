/*
You are given an undirected tree with v vertices.
The vertices can be of any one of the following colours: Red, Blue, Black.
Tree contains atleast one red and one blue node.
You can remove an edge such that we get 2 trees when none of the tree
has both red and blue colour nodes together.
Find how many such edge we can remove.

https://codeforces.com/contest/1118/problem/F1
*/
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

std::vector<int> color;
int red = 0, blue = 0, ans = 0;
std::vector<std::list<int>> tree;

std::pair<int, int> travel(int node, int parent = -1) {
	std::pair<int, int> net_count(0, 0);
	for (auto &n : tree[node]) {
		if (n == parent) continue;
		std::pair<int, int> count_stree = travel(n, node);
		ans += ((count_stree.first == 0 and count_stree.second == blue) or (count_stree.first == red and count_stree.second == 0));
		net_count.first += count_stree.first;
		net_count.second += count_stree.second;
	}
	if (color[node] == 1) ++net_count.first;
	else if (color[node] == 2) ++net_count.second;
	return net_count;
}
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

	int n;
	std::cin >> n;
	color.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> color[i];
		red += (color[i] == 1);
		blue += (color[i] == 2);
	}
	tree.resize(n + 1, std::list<int>());
	for (int i = 1; i < n; i++) {
		int u, v;
		std::cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	travel(1);
	std::cout << ans << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}