class Solution {
public:
    int maxProduct(vector<int>& nums) {
         if (nums.size() < 2) {
            return 0; 
        }
        sort(nums.rbegin(), nums.rend());
        
        return ((nums[0] - 1) * (nums[1] - 1));
    }
};