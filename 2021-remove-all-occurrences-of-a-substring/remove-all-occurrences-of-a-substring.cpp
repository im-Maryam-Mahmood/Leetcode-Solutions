class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t pos;
        while ((pos = s.find(part)) != string::npos) {
            s.replace(pos, part.length(), "");
        }
        return s;
    }
};
