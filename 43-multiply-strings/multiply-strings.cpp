class Solution {
public:
    string multiply(string num1, string num2) {
    if(num1 == "0" || num2 == "0") {
    return "0";
    }
    int m = num1.size();
    int n = num2.size();
    string result(m + n, '0');
    for(int i = m - 1; i >= 0; i--){
        for(int j = n -1; j >= 0; j--){
        int product = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
        result[i + j + 1] = product % 10 + '0';
        result[i + j] += product / 10; 
        }
    } 
    size_t pos = result.find_first_not_of('0');
    return (pos != string::npos) ? result.substr(pos) : "0";
    }
};