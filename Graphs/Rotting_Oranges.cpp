<<<<<<< HEAD
// https://leetcode.com/problems/rotting-oranges/
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

class Solution {
    bool isSafe(int row, int col, std::vector<std::vector<int>>& grid) {
        return (row >= 0 and row < grid.size() and col >= 0 and col < grid[0].size() and grid[row][col] == 1);
    }
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        std::queue<std::pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();

        std::vector<std::vector<bool>> vis(m, std::vector<bool>(n, 0));

        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == 2) { q.push({ i, j }); vis[i][j] = true; }
            }
        }

        q.push({ -1, -1 });

        int level = -1;

        while (not q.empty()) {
            std::pair<int, int> t = q.front();
            q.pop();

            if (t.first == -1 and t.second == -1) {
                ++level;
                if (q.empty()) break;
                q.push({ -1, -1 });
                continue;
            }

            if (isSafe(t.first + 1, t.second, grid) and (not vis[t.first + 1][t.second])) { vis[t.first + 1][t.second] = true; q.push({ t.first + 1, t.second }); }
            if (isSafe(t.first - 1, t.second, grid) and (not vis[t.first - 1][t.second])) { vis[t.first - 1][t.second] = true; q.push({ t.first - 1, t.second }); }
            if (isSafe(t.first, t.second + 1, grid) and (not vis[t.first][t.second + 1])) { vis[t.first][t.second + 1] = true; q.push({ t.first, t.second + 1 }); }
            if (isSafe(t.first, t.second - 1, grid) and (not vis[t.first][t.second - 1])) { vis[t.first][t.second - 1] = true; q.push({ t.first, t.second - 1 }); }
        }

        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == 1 and (not vis[i][j])) return -1;
            }
        }

        return level;
    }
};

void file_i_o() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    vec<vi> grid = { {2,1,1},{1,1,1},{0,1,2} };
    Solution S;
    std::cout << S.orangesRotting(grid) << "\n";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
=======
// https://leetcode.com/problems/rotting-oranges/
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

class Solution {
    bool isSafe(int row, int col, std::vector<std::vector<int>>& grid) {
        return (row >= 0 and row < grid.size() and col >= 0 and col < grid[0].size() and grid[row][col] == 1);
    }
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        std::queue<std::pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();

        std::vector<std::vector<bool>> vis(m, std::vector<bool>(n, 0));

        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == 2) { q.push({ i, j }); vis[i][j] = true; }
            }
        }

        q.push({ -1, -1 });

        int level = -1;

        while (not q.empty()) {
            std::pair<int, int> t = q.front();
            q.pop();

            if (t.first == -1 and t.second == -1) {
                ++level;
                if (q.empty()) break;
                q.push({ -1, -1 });
                continue;
            }

            if (isSafe(t.first + 1, t.second, grid) and (not vis[t.first + 1][t.second])) { vis[t.first + 1][t.second] = true; q.push({ t.first + 1, t.second }); }
            if (isSafe(t.first - 1, t.second, grid) and (not vis[t.first - 1][t.second])) { vis[t.first - 1][t.second] = true; q.push({ t.first - 1, t.second }); }
            if (isSafe(t.first, t.second + 1, grid) and (not vis[t.first][t.second + 1])) { vis[t.first][t.second + 1] = true; q.push({ t.first, t.second + 1 }); }
            if (isSafe(t.first, t.second - 1, grid) and (not vis[t.first][t.second - 1])) { vis[t.first][t.second - 1] = true; q.push({ t.first, t.second - 1 }); }
        }

        for (int i = 0;i < m;i++) {
            for (int j = 0;j < n;j++) {
                if (grid[i][j] == 1 and (not vis[i][j])) return -1;
            }
        }

        return level;
    }
};

void file_i_o() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    vec<vi> grid = { {2,1,1},{1,1,1},{0,1,2} };
    Solution S;
    std::cout << S.orangesRotting(grid) << "\n";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
