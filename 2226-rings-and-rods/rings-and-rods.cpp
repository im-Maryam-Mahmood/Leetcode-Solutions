class Solution {
public:
    int countPoints(string rings) {
    unordered_map<int, unordered_set<char>> rodColors;
    for(int i = 0; i < rings.size(); i += 2){
       char colors = rings[i];
        int rod = rings[i + 1] - '0';
        rodColors[rod].insert(colors);
    }  
    int count = 0;
        for (const auto& pair : rodColors) {
        if (pair.second.size() == 3) count++; 
        } 
        return count;
    }
};