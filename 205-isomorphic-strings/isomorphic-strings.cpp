class Solution {
public:
    bool isIsomorphic(string s, string t) {
        stack<int> stack_s[256], stack_t[256];
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (!stack_s[s[i]].empty() && !stack_t[t[i]].empty()) {
            if (stack_s[s[i]].top() != stack_t[t[i]].top()) return false;
        } else if (!stack_s[s[i]].empty() || !stack_t[t[i]].empty()) {
            return false;
        }
        stack_s[s[i]].push(i);
        stack_t[t[i]].push(i);
    }
    return true;
    }
};