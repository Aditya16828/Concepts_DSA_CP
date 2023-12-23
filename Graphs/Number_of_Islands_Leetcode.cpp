<<<<<<< HEAD
// https://leetcode.com/problems/number-of-islands/submissions/
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

class Solution {
    bool isSafe(int x, int y, std::vector<std::vector<char>>& grid) {
        return (x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size() and grid[x][y] == '1');
    }
    void dfs(std::pair<int, int> src, std::vector<std::vector<bool>>& vis, std::vector<std::vector<char>>& grid) {
        vis[src.first][src.second] = 1;
        if (isSafe(src.first + 1, src.second, grid) and (not vis[src.first + 1][src.second])) dfs({ src.first + 1, src.second }, vis, grid);
        if (isSafe(src.first, src.second + 1, grid) and (not vis[src.first][src.second + 1])) dfs({ src.first, src.second + 1 }, vis, grid);
        if (isSafe(src.first, src.second - 1, grid) and (not vis[src.first][src.second - 1])) dfs({ src.first, src.second - 1 }, vis, grid);
        if (isSafe(src.first - 1, src.second, grid) and (not vis[src.first - 1][src.second])) dfs({ src.first - 1, src.second }, vis, grid);
    }
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int comp = 0;
        std::vector<std::vector<bool>> vis(row, std::vector<bool>(col, 0));
        for (int i = 0;i < row;i++) {
            for (int j = 0;j < col;j++) {
                if (grid[i][j] == '1' and (not vis[i][j])) {
                    ++comp;
                    dfs({ i, j }, vis, grid);
                }
            }
        }
        return comp;
    }
};

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....



#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
=======
// https://leetcode.com/problems/number-of-islands/submissions/
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

class Solution {
    bool isSafe(int x, int y, std::vector<std::vector<char>>& grid) {
        return (x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size() and grid[x][y] == '1');
    }
    void dfs(std::pair<int, int> src, std::vector<std::vector<bool>>& vis, std::vector<std::vector<char>>& grid) {
        vis[src.first][src.second] = 1;
        if (isSafe(src.first + 1, src.second, grid) and (not vis[src.first + 1][src.second])) dfs({ src.first + 1, src.second }, vis, grid);
        if (isSafe(src.first, src.second + 1, grid) and (not vis[src.first][src.second + 1])) dfs({ src.first, src.second + 1 }, vis, grid);
        if (isSafe(src.first, src.second - 1, grid) and (not vis[src.first][src.second - 1])) dfs({ src.first, src.second - 1 }, vis, grid);
        if (isSafe(src.first - 1, src.second, grid) and (not vis[src.first - 1][src.second])) dfs({ src.first - 1, src.second }, vis, grid);
    }
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int comp = 0;
        std::vector<std::vector<bool>> vis(row, std::vector<bool>(col, 0));
        for (int i = 0;i < row;i++) {
            for (int j = 0;j < col;j++) {
                if (grid[i][j] == '1' and (not vis[i][j])) {
                    ++comp;
                    dfs({ i, j }, vis, grid);
                }
            }
        }
        return comp;
    }
};

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....



#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
