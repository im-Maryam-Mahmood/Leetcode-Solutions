class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = count(nums.begin(), nums.end(), 1);
        if (k == 0 || k == n) return 0;
        int maxOnes = 0, currentOnes = 0;
        for (int i = 0; i < k; ++i) currentOnes += nums[i];
        maxOnes = currentOnes;
        for (int i = k; i < n + k; ++i) {
            currentOnes += nums[i % n] - nums[i - k];
            maxOnes = std::max(maxOnes, currentOnes);
        }
        return k - maxOnes;
    }
};