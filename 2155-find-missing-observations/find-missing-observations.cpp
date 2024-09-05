class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int total_sum = mean * (n + m);
        int current_sum = 0;
        for (int roll : rolls) current_sum += roll;
        int missing_sum = total_sum - current_sum;
        if (missing_sum < n || missing_sum > 6 * n) return {};
        vector<int> result(n, missing_sum / n);
        int remainder = missing_sum % n;
        for (int i = 0; i < remainder; ++i) result[i]++;
        return result;
    }
};
