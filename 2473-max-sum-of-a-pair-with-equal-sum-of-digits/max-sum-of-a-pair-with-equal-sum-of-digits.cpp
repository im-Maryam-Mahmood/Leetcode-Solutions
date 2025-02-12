class Solution {
public:
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> maxNum;
        int maxSum = -1;
        for (int num : nums) {
            int digitSum = sumOfDigits(num);
            if (maxNum.find(digitSum) != maxNum.end()) {
                maxSum = max(maxSum, maxNum[digitSum] + num);
            }
            maxNum[digitSum] = max(maxNum[digitSum], num);
        }
        return maxSum;
    }
};
