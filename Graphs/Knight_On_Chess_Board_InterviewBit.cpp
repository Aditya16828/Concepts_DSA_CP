// https://www.interviewbit.com/problems/292/
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

bool isSafe(int x, int y, int m, int n) {
	return (x >= 1 and x <= m and y >= 1 and y <= n);
}

int knight(int m, int n, int c, int d, int e, int f) {
	pii src = {c, d};
	pii dest = {e, f};
	vec<vec<bool>> vis(m + 1, vec<bool>(n + 1, false));
	std::queue<pii> q;
	vi dx {1, 1, 2, 2, -1, -1, -2, -2};
	vi dy {2, -2, 1, -1, 2, -2, 1, -1};
	q.push(src);
	q.push({ -1, -1});
	vis[c][d] = true;
	int moves = 0;
	while (not q.empty()) {
		pii curr = q.front();
		q.pop();
		int x = curr.first;
		int y = curr.second;
		if (x == -1 and y == -1) {
			++moves;
			if (q.empty()) break;
			q.push({ -1, -1});
		}
		if (x == e and y == f) {
			return moves;
		}
		for (int i = 0; i < 8; i++) {
			if (isSafe(x + dx[i], y + dy[i], m, n)) {
				if (vis[x + dx[i]][y + dy[i]]) continue;
				else {
					vis[x + dx[i]][y + dy[i]] = true;
					q.push({x + dx[i], y + dy[i]});
				}
			}
		}
	}
	return -1;
}


int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	file_i_o();
	// Write your code here....



#ifndef ONLINE_JUDGE
	clock_t end = clock();
	std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
	return 0;
}