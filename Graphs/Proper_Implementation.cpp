#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

using namespace std;

// adjancency list
class graph {
public:
	int v;
	std::list<int> *arr;

	graph(int v) {
		this->v = v;
		this->arr = new std::list<int>[v];
	}

	void add_edge(int u, int v, bool undir = false) {
		this->arr[u].push_back(v);
		if (undir) {
			this->arr[v].push_back(u);
		}
	}
};

int main()
{
	clock_t begin = clock();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v;
	std::cin >> v;
	graph g(v);
	int e;
	std::cin >> e;
	while (e--) {
		int u, v;
		std::cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}
