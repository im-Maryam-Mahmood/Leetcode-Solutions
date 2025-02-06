class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int numsLength = nums.size();
        sort(nums.begin(), nums.end());
        int totalNumberOfTuples = 0;
        for (int aIndex = 0; aIndex < numsLength; aIndex++) {
            for (int bIndex = numsLength - 1; bIndex >= aIndex + 1; bIndex--) {
                int product = nums[aIndex] * nums[bIndex];
                unordered_set<int> possibleDValues;
                for (int cIndex = aIndex + 1; cIndex < bIndex; cIndex++) {
                    if (product % nums[cIndex] == 0) {
                        int dValue = product / nums[cIndex];
                        if (possibleDValues.find(dValue) !=
                            possibleDValues.end()) {
                            totalNumberOfTuples += 8;
                        }
                        possibleDValues.insert(nums[cIndex]);
                    }
                }
            }
        }

        return totalNumberOfTuples;
    }
};