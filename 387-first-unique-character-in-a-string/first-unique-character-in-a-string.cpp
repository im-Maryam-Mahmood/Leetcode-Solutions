class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> charcount(26,0);
        for( char c : s) charcount[c - 'a']++;
        for( int i = 0; i < s.length(); i++ ) 
            if( charcount[ s[i] - 'a' ] == 1) return i;
        return -1;
    }
};