class Solution {
public:
    int findNumbers(vector<int>& nums) {
    int count = 0;
    for(int num : nums){
        int digits = log10(num) + 1;
        if(digits %2 == 0){
            count++;
        }
    } 
    return count;   
    }
};