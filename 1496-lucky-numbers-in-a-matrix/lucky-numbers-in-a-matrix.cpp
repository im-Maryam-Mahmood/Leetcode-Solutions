class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> luckyNumbers;
        for (int i = 0; i < matrix.size(); ++i) {
            int minElement = INT_MAX, minIndex = -1;
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] < minElement) {
                    minElement = matrix[i][j];
                    minIndex = j;
                }
            }
            bool isLucky = true;
            for (int k = 0; k < matrix.size(); ++k) {
                if (matrix[k][minIndex] > minElement) {
                    isLucky = false;
                    break;
                }
            }
            
            if (isLucky) luckyNumbers.push_back(minElement);
        }
        return luckyNumbers;
    }
};