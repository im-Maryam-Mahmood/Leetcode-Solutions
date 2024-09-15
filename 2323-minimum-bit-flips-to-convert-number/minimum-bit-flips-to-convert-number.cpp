class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal; 
        int count = 0;
        while (x > 0) {
            count += x & 1; 
            x >>= 1;       
        }
        return count;
    }
};