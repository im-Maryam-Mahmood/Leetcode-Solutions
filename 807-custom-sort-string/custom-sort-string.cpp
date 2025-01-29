class Solution {
public:
    string customSortString(string order, string s) {
    unordered_map<char, int>count;
    for(char ch : s){
    count[ch]++;
    }    
    string result = "";
    for(char ch : order){
        if(count.find(ch) != count.end()){
        result += string(count[ch], ch);
        count.erase(ch);
        }
    }
    for(auto& pair : count){
        result += string(pair.second, pair.first);
    }
    return result;
    }
};