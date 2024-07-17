class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0, maxsub = 0, n = s.length();
        if( n == 0 ) return 0;
        unordered_map<char, int> map;
        for( int i = 0; i < n; i++) {
            if(map.find(s[i]) != map.end())
                maxsub = max (maxsub, map[s[i]] + 1);
        map[s[i]] = i;
        maxlength = max ( maxlength, i - maxsub + 1);
        }
        return maxlength;
    }
};