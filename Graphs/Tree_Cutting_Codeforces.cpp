<<<<<<< HEAD
// https://codeforces.com/problemset/problem/1118/F1
// Solution Video: https://www.youtube.com/watch?v=sjmeld7NA-4
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

std::vector<std::list<int>> graph;

std::vector<int> a;
int reds = 0, blues = 0, cuts = 0;

std::pair<int, int> traverse(int node, int parent = -1) {
	std::pair<int, int> total(0, 0); // {red, blue}
	for (auto &n : graph[node]) {
		if (n == parent) continue;

		std::pair<int, int> childs = traverse(n, node); // returns the number of red and blue nodes in their childs subtree
		int red_child = childs.first;
		int blue_child = childs.second;

		if ((red_child == reds and blue_child == 0) or (blue_child == blues and red_child == 0))
			++cuts;

		total.first += red_child;
		total.second += blue_child;
	}
	if (a[node] == 1) {++total.first;}
	if (a[node] == 2) {++total.second;}
	return total;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin >> n;
	a.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if (a[i] == 1) reds++;
		if (a[i] == 2) blues++;
	}

	graph.resize(n + 1, std::list<int>());
	int edges = n - 1;
	while (edges--) {
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	traverse(1);
	std::cout << cuts << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
=======
// https://codeforces.com/problemset/problem/1118/F1
// Solution Video: https://www.youtube.com/watch?v=sjmeld7NA-4
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

std::vector<std::list<int>> graph;

std::vector<int> a;
int reds = 0, blues = 0, cuts = 0;

std::pair<int, int> traverse(int node, int parent = -1) {
	std::pair<int, int> total(0, 0); // {red, blue}
	for (auto &n : graph[node]) {
		if (n == parent) continue;

		std::pair<int, int> childs = traverse(n, node); // returns the number of red and blue nodes in their childs subtree
		int red_child = childs.first;
		int blue_child = childs.second;

		if ((red_child == reds and blue_child == 0) or (blue_child == blues and red_child == 0))
			++cuts;

		total.first += red_child;
		total.second += blue_child;
	}
	if (a[node] == 1) {++total.first;}
	if (a[node] == 2) {++total.second;}
	return total;
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int n;
	std::cin >> n;
	a.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if (a[i] == 1) reds++;
		if (a[i] == 2) blues++;
	}

	graph.resize(n + 1, std::list<int>());
	int edges = n - 1;
	while (edges--) {
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	traverse(1);
	std::cout << cuts << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
