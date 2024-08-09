class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int magicSqr = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int r = 0; r + 2 < n; ++r) {
            for (int c = 0; c + 2 < m; ++c) {
                if (checkMagicSqr(grid, r, c)) {
                    ++magicSqr;
                }
            }
        }
        return magicSqr;
    }
    bool checkMagicSqr(vector<vector<int>>& grid, int r, int c) {
        vector<int> present(10, 0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int val = grid[r + i][c + j];
                if (val < 1 || val > 9)
                    return false;
                if (present[val])
                    return false;
                present[val] = 1;
            }
        }
        // diagonal sum
        int d1 = grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2];
        int d2 = grid[r + 2][c] + grid[r + 1][c + 1] + grid[r][c + 2];
        if (d1 != d2) {
            return false;
        }
        // check row and col sum equal to d1(or d2)?
        int r1 = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];
        int r2 = grid[r + 1][c] + grid[r + 1][c + 1] + grid[r + 1][c + 2];
        int r3 = grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2];
        if (r1 != d1 || r2 != d1 || r3 != d1) {
            return false;
        }
        int c1 = grid[r][c] + grid[r + 1][c] + grid[r + 2][c];
        int c2 = grid[r][c + 1] + grid[r + 1][c + 1] + grid[r + 2][c + 1];
        int c3 = grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2];
        if (c1 != d1 || c2 != d1 || c3 != d1) {
            return false;
        }
        return true;
    }
};