class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int total = rows * cols;
        int steps = 1;  
        int r = rStart, c = cStart;
        int direction = 0;  
        vector<int> dr = {0, 1, 0, -1};
        vector<int> dc = {1, 0, -1, 0};

        result.push_back({r, c});
        while (result.size() < total) {
            for (int i = 0; i < 2; ++i) { 
                for (int j = 0; j < steps; ++j) {
                    r += dr[direction];
                    c += dc[direction];
                    if (r >= 0 && r < rows && c >= 0 && c < cols) 
                    result.push_back({r, c});
                }
                direction = (direction + 1) % 4;  
            }
            steps++;
        }

        return result;
    }
};