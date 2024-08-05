class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> map;
        for( auto ch : arr ) map[ch]++;
        int count = 0;
        for( const auto& str :arr) {
            if( map[str] == 1 ) count++;
            if( count == k) return str;
        }
        return "";
    }
};