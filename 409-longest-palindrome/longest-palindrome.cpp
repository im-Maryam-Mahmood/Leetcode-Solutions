class Solution {
public:
    int longestPalindrome(string s) {
        int count[128] = {0}; 
        for (char c : s)
            count[c]++;
        int length = 0;
        bool oddFound = false;
        for (int i = 0; i < 128; ++i) {
            length += count[i] / 2 * 2;
            if (count[i] % 2 != 0)
                oddFound = true;
        }
        
        return length + (oddFound ? 1 : 0); 
    }
};