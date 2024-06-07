class Solution {
public:
    string makeGood(string s) {
        stack<char> S;
        string res;
        for( char c : s){
            if( !S.empty() && abs(S.top() - c) == 32) S.pop();
            else S.push(c);
        }
        while( !S.empty()) {
        res =  S.top() + res;
        S.pop();}
        return res;
    }
};