class Solution {
public:
    int mySqrt(int x) {
        int i = 0 ; 
        int j =  x;
        while(i <= j){
            long long mid = i + (j-i)/2;
            if(mid*mid == x) return mid;
            else if(mid*mid < x) i = mid+1;
            else j = mid-1;
        }
        return j;
    }
};