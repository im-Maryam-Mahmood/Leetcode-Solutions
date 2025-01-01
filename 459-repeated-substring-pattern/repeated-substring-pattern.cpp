class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int len = 1; len <= n / 2; ++len) {
            if (n % len == 0) {
                string sub = s.substr(0, len);
                int repeats = n / len;
                string constructed;
                for (int i = 0; i < repeats; ++i) {
                    constructed += sub;
                }
                if (constructed == s) {
                    return true;
                }
            }
        }
        return false;
    }
};