class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (map.find(diff) != map.end()) return { map[diff], i };
            map[nums[i]] = i;
        }
        return {};
    }
};