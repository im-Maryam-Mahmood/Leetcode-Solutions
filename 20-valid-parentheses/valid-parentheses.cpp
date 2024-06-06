class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
         for( char c : s){
             if (c =='{' || c == '(' || c == '['){
                S.push(c);
             }else {
                if(S.empty()
                ||( c == ')' && S.top() !='(' )
                ||( c == '}' && S.top() !='{' )
                ||( c == ']' && S.top() !='[' )){
                return false;
            }
            S.pop();     
            }
        }
        return S.empty();
    }
};