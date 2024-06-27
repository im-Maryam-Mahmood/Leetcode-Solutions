class Solution {
public:
    bool checkRecord(string s) {
        int A = 0;
        int L = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') {
                A++;
                if (A >= 2) {
                    return false; // More than 1 absence
                }
                L = 0; // Reset L because it's not 'L'
            } else if (s[i] == 'L') {
                L++;
                if (L >= 3) {
                    return false; // 3 or more consecutive late days
                }
            } else {
                L = 0; // Reset streak if not 'L'
            }
        }
        return true; 
    }
};