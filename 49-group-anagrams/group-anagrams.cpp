class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int maxlength = 0;
       unordered_map <string, vector<string>> anagram;
        int n = strs.size();
        if( n == 0 ) return {};
        for( int i = 0; i < n; i++ ) {
            string sub;
            sub = strs[i];
            sort(sub.begin(), sub.end());
            anagram[sub].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for( auto &groups : anagram ) res.push_back(groups.second);
        return res;
    }
};