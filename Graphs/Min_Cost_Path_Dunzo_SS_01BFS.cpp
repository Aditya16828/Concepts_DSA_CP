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

vec<std::list<pii>> g;

bool isSafe(int x, int y, int m, int n) {
	return (x >= 0 and y >= 0 and x < m and y < n);
}

int bfs(int src, int dest) {
	vec<int> cost(g.size(), INT_MAX); // cost for going to ith node from the src
	cost[src] = 0;
	std::deque<int> q;
	q.push_front(src);
	while (!q.empty()) {
		int curr = q.front();
		q.pop_front();
		iter_all(ne, g[curr]) {
			if (cost[ne.first] > cost[curr] + ne.second) { // if the cost to go directly from src to node ne > cost to go from src to parent node + cost to go from parent node to its child node ne.
				cost[ne.first] = cost[curr] + ne.second;
				if (ne.second) {
					q.push_back(ne.first);
				} else {
					q.push_front(ne.first);
				}
			}
		}
	}
	return cost[dest];
}

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....

	int m, n;
	std::cin >> m >> n;
	vec<vec<char>> grid(m, vec<char>(n));
	loop(i, 0, m - 1) {
		loop(j, 0, n - 1) {
			std::cin >> grid[i][j];
		}
	}

	g.resize(m * n);

	int dir[4] = {'U', 'D', 'L', 'R'};
	pii delta[4] = {{ -1, 0}, {1, 0}, { 0, -1}, {0, 1}};

	loop(i, 0, m - 1) {
		loop(j, 0, n - 1) {
			int label = i * n + j;
			loop(d, 0, 3) {
				if (not isSafe(i + delta[d].first, j + delta[d].second, m, n)) continue;
				if (dir[d] == grid[i][j]) {
					g[label].push_back({(i + delta[d].first) * n + (j + delta[d].second), 0});
				} else {
					g[label].push_back({(i + delta[d].first) * n + (j + delta[d].second), 1});
				}
			}
		}
	}

	loop(i, 0, g.size() - 1) {
		std::cout << i << "->";
		iter_all(el, g[i]) {
			std::cout << "{" << el.first << ", " << el.second << "}, ";
		}
		std::cout << "\n";
	}
	std::cout << bfs(0, g.size() - 1) << "\n";

#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}