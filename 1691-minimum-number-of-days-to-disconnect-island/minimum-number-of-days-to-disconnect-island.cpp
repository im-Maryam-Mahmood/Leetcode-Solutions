class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        auto countIslands = [&](vector<vector<int>>& grid) -> int {
            int m = grid.size(), n = grid[0].size(), islands = 0;
            vector<vector<int>> visited(m, vector<int>(n, 0));
            
            function<void(int, int)> dfs = [&](int i, int j) {
                if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || grid[i][j] == 0) return;
                visited[i][j] = 1;
                dfs(i - 1, j); dfs(i + 1, j); dfs(i, j - 1); dfs(i, j + 1);
            };
            
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1 && !visited[i][j]) {
                        islands++;
                        dfs(i, j);
                    }
                }
            }
            return islands;
        };
        
        int initialIslands = countIslands(grid);
        if (initialIslands != 1) return 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIslands(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
