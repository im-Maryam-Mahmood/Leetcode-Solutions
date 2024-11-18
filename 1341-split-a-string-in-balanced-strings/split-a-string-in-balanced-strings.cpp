class Solution {
public:
    int balancedStringSplit(string s) {
    int balance = 0, count = 0;
    for(char c : s){
        balance += (c == 'L') ? 1 : -1;
        if(balance == 0){
            count++;
        }
    }
    return count;    
    }
};