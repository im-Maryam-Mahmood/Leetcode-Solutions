class Solution {
public:
    string convertToBase7(int num) {
    if(num == 0) return "0";
    string result;
    bool negative  = num < 0;
    if(negative)num = -num;
    while (num > 0){
    result = to_string(num % 7) + result;
    num /= 7;
    }
    return negative ? "-" + result : result;
    }
};