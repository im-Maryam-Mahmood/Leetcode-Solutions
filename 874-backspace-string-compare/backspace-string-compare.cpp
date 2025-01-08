class Solution {
public:
    bool backspaceCompare(string s, string t) {
        std::stack<char> stk1, stk2;
        
        for (char ch : s) {
            if (ch == '#') {
                if (!stk1.empty()) stk1.pop();
            } else 
                stk1.push(ch);
        }
        
        for (char ch : t) {
            if (ch == '#') {
                if (!stk2.empty()) stk2.pop();
            } else stk2.push(ch);
        }
        
        return stk1 == stk2;
    }
};
