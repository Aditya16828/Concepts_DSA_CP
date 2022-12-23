// https://leetcode.com/problems/sudoku-solver/submissions/
#include <bits/stdc++.h>
#define ll long long int

class Solution {
public:
    bool isSafe(std::vector<std::vector<char>>& b, int i, int j, char num) {
        for (int row = 0;row < 9;row++) {
            if (b[row][j] - '0' == num) return false;
        }
        for (int col = 0;col < 9;col++) {
            if (b[i][col] - '0' == num) return false;
        }
        for (int x = (i / 3) * 3;x <= ((i / 3) * 3) + 2;x++) {
            for (int y = (j / 3) * 3;y <= ((j / 3) * 3) + 2;y++) {
                if (b[x][y] - '0' == num) return false;
            }
        }
        return true;
    }

    bool helper(std::vector<std::vector<char>>& b, int r, int c) {
        if (c == 9) {
            return helper(b, r + 1, 0);
        }
        if (r == 9) return true;
        if (b[r][c] == '.') {
            for (int n = 1;n <= 9;n++) {
                if (isSafe(b, r, c, n)) {
                    b[r][c] = n + '0';
                    bool res = helper(b, r, c + 1);
                    if (res) return true;
                    b[r][c] = '.';
                }
            }
            return false;
        } else return helper(b, r, c + 1);
    }

    void solveSudoku(std::vector<std::vector<char>>& board) {
        bool res = helper(board, 0, 0);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);



    return 0;
}
