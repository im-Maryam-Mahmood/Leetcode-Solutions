class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stack;
        string result;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') stack.push(result.length());
            else if (s[i] == ')') {
                int start = stack.top();
                stack.pop();
                reverse(result.begin() + start, result.end());
            } else result += s[i];
        }
        return result;
    }
};