class Solution {
public:
    int maxProduct(vector<int>& nums) {
         if (nums.size() < 2) {
            return 0; // Or handle the error as needed
        }
        int max1 = 0, max2 = 0;

        for (int num : nums) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }
        }

        // Calculate and return the product (max1 - 1) * (max2 - 1)
        return (max1 - 1) * (max2 - 1);
    }
};