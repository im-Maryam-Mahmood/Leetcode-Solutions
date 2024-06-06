class Solution {
public:
    bool isPalindrome(string s) {
        string S = "";
        for( char c :s){
            if(isalnum(c)){
                S += tolower(c);
            }
        }
        int i = 0, j = S.length() - 1;
        while(i < j){
            if(S[i] != S[j]){
            return false;
            }
        i++;
        j--;
        }
        return true;
    }
};