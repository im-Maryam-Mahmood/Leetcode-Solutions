class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> s;
        for (int i = 0; i < n; i++) {
            s.push_back(nums[i]);
            s.push_back(nums[i + n]);
        }
        return s;
    }
};
