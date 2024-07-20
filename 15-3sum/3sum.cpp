class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            unordered_set<int> map;
            for (int j = i + 1; j < n; ++j) {
                int complement = -nums[i] - nums[j];
                if (map.count(complement)) {
                    res.push_back({nums[i], nums[j], complement});
                    while (j + 1 < n && nums[j] == nums[j + 1]) ++j;
                }
                map.insert(nums[j]);
            }
        }
        return res;
    }
};