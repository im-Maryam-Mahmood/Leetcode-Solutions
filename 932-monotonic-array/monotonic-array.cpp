class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if ( nums.empty()){
            return true;
        }
        bool inc = true;
        bool dec = true;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                inc = false;
            }
            if (nums[i - 1] < nums[i]) {
                dec = false;
            }
        }
    
    return inc || dec;
    }
};