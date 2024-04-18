class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int P = 0;
        int R = grid.size();
        int C = grid[0].size();
        
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (grid[r][c] == 1) {
                    P += 4;
                    if (r > 0 && grid[r-1][c] == 1) {
                        P -= 2;
                    }
                    if (c > 0 && grid[r][c-1] == 1) {
                        P -= 2;
                    }
                }
            }
        }
        return P;
    }
};