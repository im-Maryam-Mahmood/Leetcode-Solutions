class Solution {
public:
    int romanToInt(string s) {
    unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
    if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
        count -= roman[s[i]];
            } else {
                count += roman[s[i]];
            }
        }
        
        return count;
    }
};