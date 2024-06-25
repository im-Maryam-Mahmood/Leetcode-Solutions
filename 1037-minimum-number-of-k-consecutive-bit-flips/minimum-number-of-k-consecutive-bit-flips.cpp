class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
    int n = nums.size();
        vector<int> diff(n + 1, 0);
        int flipCount = 0; 
        int currentFlips = 0;
        
        for (int i = 0; i < n; ++i) {
            currentFlips += diff[i];
            if ((nums[i] + currentFlips) % 2 == 0) {
                if (i + k > n) 
                    return -1;
                ++flipCount;
                ++currentFlips;
                ++diff[i + k];
            }
        }
        return flipCount;
    }
};
