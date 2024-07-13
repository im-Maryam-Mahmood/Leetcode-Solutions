class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0; 
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        for (int i = 0; i <= nums.size() - k; ++i) 
        minDiff = min(minDiff, nums[i + k - 1] - nums[i]);
        return minDiff;
    }
};