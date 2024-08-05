class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        generateCombinations(result, combination, k, n, 1);
        return result;
    }
    void generateCombinations(vector<vector<int>>& result, vector<int>& combination, int k, int n, int start) {
        if (combination.size() == k) {
            if (n == 0) result.push_back(combination);
            return;
        }
        for (int i = start; i <= 9; ++i) {
            combination.push_back(i);
            generateCombinations(result, combination, k, n - i, i + 1);
            combination.pop_back();
        }
    }
};
