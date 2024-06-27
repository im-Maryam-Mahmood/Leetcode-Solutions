class Solution {
public:
    bool checkRecord(string s) {
        int A = 0;
        int L = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                A++;
                if (A >= 2) {
                    return false;
                }
                L = 0; 
            } else if (s[i] == 'L') {
                L++;
                if (L >= 3) {
                    return false;
                }
            } else {
                L = 0;
            }
        }
        return true; 
    }
};