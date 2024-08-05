class Solution {
public:
    double angleClock(int hour, int minutes) {
        double angle = abs( (minutes * 6 ) - ((hour % 12) * 30 + (minutes * 0.5)));
        return min( angle, 360 - angle);
    }
};