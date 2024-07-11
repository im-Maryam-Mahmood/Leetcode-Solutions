class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> current;
        string result;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') current.push(result.length());
            else if (s[i] == ')') {
                int start = current.top();
                current.pop();
                reverse(result.begin() + start, result.end());
            } else result += s[i];
        }
        return result;
    }
};