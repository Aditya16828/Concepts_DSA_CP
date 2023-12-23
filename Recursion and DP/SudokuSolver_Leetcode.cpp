<<<<<<< HEAD
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

class Solution {
    bool isSafe(std::vector<std::vector<char>>& board, int row, int col, int num) {
        for (int i = 0;i < 9;i++) {
            if (board[i][col] - '0' == num) return false;
        }
        for (int i = 0;i < 9;i++) {
            if (board[row][i] - '0' == num) return false;
        }

        int lo_row = (row / 3) * 3, hi_row = (row / 3 + 1) * 3;
        int lo_col = (col / 3) * 3, hi_col = (col / 3 + 1) * 3;

        for (int i = lo_row;i < hi_row;i++) {
            for (int j = lo_col;j < hi_col;j++) {
                if (board[i][j] - '0' == num) return false;
            }
        }
        return true;
    }

    bool helper(std::vector<std::vector<char>>& board, int row, int col) {
        if (row == 9) {
            return true;
        }
        if (col == 9) {
            return helper(board, row + 1, 0);
        }
        if (board[row][col] == '.') {
            for (int i = 1;i <= 9;i++) {
                if (isSafe(board, row, col, i)) {
                    board[row][col] = (char)('0' + i);
                    bool t = helper(board, row, col + 1);
                    if (t) return true;
                    board[row][col] = '.';
                }
            }
            return false;
        }
        return helper(board, row, col + 1);
    }
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        helper(board, 0, 0);
    }
};

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    Solution s;
    std::vector<std::vector<char>> board(9, std::vector<char>(9, '.'));
    for (int i = 0;i < 9;i++) {
        for (int j = 0;j < 9;j++) {
            std::cin >> board[i][j];
        }
    }
    s.solveSudoku(board);
    for (auto& row : board) {
        for (auto& col : row) {
            std::cout << col << "|";
        }
        std::cout << "\n";
    }

#ifndef ONLINE_JUDGE 
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif 
    return 0;
}
=======
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

class Solution {
    bool isSafe(std::vector<std::vector<char>>& board, int row, int col, int num) {
        for (int i = 0;i < 9;i++) {
            if (board[i][col] - '0' == num) return false;
        }
        for (int i = 0;i < 9;i++) {
            if (board[row][i] - '0' == num) return false;
        }

        int lo_row = (row / 3) * 3, hi_row = (row / 3 + 1) * 3;
        int lo_col = (col / 3) * 3, hi_col = (col / 3 + 1) * 3;

        for (int i = lo_row;i < hi_row;i++) {
            for (int j = lo_col;j < hi_col;j++) {
                if (board[i][j] - '0' == num) return false;
            }
        }
        return true;
    }

    bool helper(std::vector<std::vector<char>>& board, int row, int col) {
        if (row == 9) {
            return true;
        }
        if (col == 9) {
            return helper(board, row + 1, 0);
        }
        if (board[row][col] == '.') {
            for (int i = 1;i <= 9;i++) {
                if (isSafe(board, row, col, i)) {
                    board[row][col] = (char)('0' + i);
                    bool t = helper(board, row, col + 1);
                    if (t) return true;
                    board[row][col] = '.';
                }
            }
            return false;
        }
        return helper(board, row, col + 1);
    }
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        helper(board, 0, 0);
    }
};

int main(int argc, char const* argv[]) {
    clock_t begin = clock();
    file_i_o();
    // Write your code here....

    Solution s;
    std::vector<std::vector<char>> board(9, std::vector<char>(9, '.'));
    for (int i = 0;i < 9;i++) {
        for (int j = 0;j < 9;j++) {
            std::cin >> board[i][j];
        }
    }
    s.solveSudoku(board);
    for (auto& row : board) {
        for (auto& col : row) {
            std::cout << col << "|";
        }
        std::cout << "\n";
    }

#ifndef ONLINE_JUDGE 
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif 
    return 0;
}
>>>>>>> 24a80fac1064910ae51f09e81777487a1aaee3b1
