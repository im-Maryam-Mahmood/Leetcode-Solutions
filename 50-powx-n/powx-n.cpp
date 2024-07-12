class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n == -1) return 1 / x;
        double i = myPow(x, n / 2);
        double j = myPow(x, n % 2);
        return i * i * j;
    }
};
