class Solution {
public:
    int getLucky(string s, int k) {
        string num;
        for (char c : s) {
            int val = c - 'a' + 1; 
            num += to_string(val);  
        }
        int result = 0;
        for (char c : num) result += c - '0'; 
        while (--k > 0) {
            int sum = 0;
            while (result > 0) {
                sum += result % 10;
                result /= 10;
            }
            result = sum;
        }
        return result;
    }
};