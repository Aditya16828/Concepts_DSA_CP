/*
Given a graph, calculate all paths between 2 vertices
OR
Given a graph, check whether there is a path between any 2 vertices.
*/
#include <bits/stdc++.h>
#define ll long long int
#define mod (long long int)(1e9 + 7)

std::vector<std::list<int>> graph;

bool has_path(int start, int end, std::vector<bool> &vis) {
	if (start == end) return true;
	vis[start] = true;
	for (auto &neighbour : graph[start]) {
		if (not vis[neighbour]) {
			bool available = has_path(neighbour, end, vis);
			if (available) return true;
		}
	}
	return false;
}

std::vector<std::vector<int>> res;
void all_paths(int start, int end, std::vector<bool> &vis, std::vector<int> &path) {
	if (start == end) {
		path.push_back(end);
		res.push_back(path);
		path.pop_back();
		return;
	}
	vis[start] = true;
	path.push_back(start);
	for (auto &n : graph[start]) {
		if (not vis[n]) {
			all_paths(n, end, vis, path);
		}
	}
	vis[start] = false;
	path.pop_back();
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

	int vertices, edges;
	std::cin >> vertices >> edges;
	graph.resize(vertices + 1, std::list<int>());
	while (edges--) {
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	std::vector<bool> visited(vertices + 1, false);
	//std::cout << (has_path(1, 5, visited) ? "Yes" : "No");
	std::vector<int> paths;
	all_paths(1, 5, visited, paths);
	for (auto i : res) {
		for (auto j : i) {
			std::cout << j << " ";
		}
		std::cout << "\n";
	}


#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\n\nExecution time: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms ";
#endif
	return 0;
}