class Solution {
public:
    bool isPerfectSquare(int num) {
        if ( num < 2 ) return true;
        long left = 2, right = num / 2, mid, p_square;
        while ( left <= right ) {
            mid = left + (right - left) / 2;
            p_square = mid * mid;
            if ( p_square == num ) return true;
            else if ( p_square < num ) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
