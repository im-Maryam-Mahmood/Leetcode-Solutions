#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        int moves = 0;
        int expected = nums[0];
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < expected) {
                moves += expected - nums[i];
                nums[i] = expected;
            }
            expected = nums[i] + 1;
        }
        
        return moves;
    }
};
