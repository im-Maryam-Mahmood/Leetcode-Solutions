class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int longestPrefixSum = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
                longestPrefixSum = sum;
            } else break;
        }
        unordered_set<int> numSet(nums.begin(), nums.end());
        for (int x = longestPrefixSum; ; ++x) {
            if (numSet.find(x) == numSet.end()) return x;
        }
    }
};