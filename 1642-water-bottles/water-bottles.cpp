class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int usedBottles = 0;
        while(numBottles >= numExchange){
           usedBottles += numExchange;
            numBottles -= numExchange;
            numBottles++;
        }
    return numBottles + usedBottles;
    }
};