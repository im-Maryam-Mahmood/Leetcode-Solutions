class Solution {
public:
    vector<string> generateParenthesis(int n) {
    vector<string> result;
    vector<pair<string, pair<int, int>>> stack;
    stack.push_back({"", {0, 0}});
    while (!stack.empty()) {
        auto [current, counts] = stack.back();
        stack.pop_back();
        int open = counts.first, close = counts.second;
        if (current.length() == n * 2) {
            result.push_back(current);
            continue;
        }
        if (open < n) stack.push_back({current + "(", {open + 1, close}});
        if (close < open) 
        stack.push_back({current + ")", {open, close + 1}});
    }
    return result;
    }
};