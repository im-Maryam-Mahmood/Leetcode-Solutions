class Solution {
public:
    int minDifference(vector<int>& nums) {
         int n = nums.size();
    if (n <= 4) return 0; 
    sort(nums.begin(), nums.end());
    int result = INT_MAX;
    for (int i = 0; i <= 3; ++i) {
        result = std::min(result, nums[n - 1 - (3 - i)] - nums[i]);
    }
    return result;
    }
};