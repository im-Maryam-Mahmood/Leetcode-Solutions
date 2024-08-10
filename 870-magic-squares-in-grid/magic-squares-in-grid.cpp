class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows - 2; ++i) {
            for (int j = 0; j < cols - 2; ++j) {
                if (isMagic(grid, i, j)) {
                    count++;
                }
            }
        }
        return count;
    }

    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        int digits[10] = {0};
        if (r + 2 >= grid.size() || c + 2 >= grid[0].size()) return false;
        for (int i = r; i < r + 3; ++i) {
            for (int j = c; j < c + 3; ++j) {
                int num = grid[i][j];
                if (num < 1 || num > 9 || digits[num]) return false;
                digits[num] = 1;
            }
        }
        return (grid[r][c] + grid[r][c+1] + grid[r][c+2] == 15 &&
                grid[r+1][c] + grid[r+1][c+1] + grid[r+1][c+2] == 15 &&
                grid[r+2][c] + grid[r+2][c+1] + grid[r+2][c+2] == 15 &&
                grid[r][c] + grid[r+1][c] + grid[r+2][c] == 15 &&
                grid[r][c+1] + grid[r+1][c+1] + grid[r+2][c+1] == 15 &&
                grid[r][c+2] + grid[r+1][c+2] + grid[r+2][c+2] == 15 &&
                grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] == 15 &&
                grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] == 15);
    }
};
