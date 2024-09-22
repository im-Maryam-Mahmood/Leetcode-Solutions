class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedSet(allowed.begin(), allowed.end());
    int consistentCount = 0;
    for (const string& word : words) {
        bool isConsistent = true;
        for (char c : word) {
            if (allowedSet.find(c) == allowedSet.end()) {
                isConsistent = false;
                break;
            }
        }
        if (isConsistent) consistentCount++;
    }
    return consistentCount;
    }
};