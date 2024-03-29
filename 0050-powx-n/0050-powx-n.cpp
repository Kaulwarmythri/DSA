class Solution {
public:
    double myPow(double x, int n) {
        if(!n)
            return 1;
        
        if(n < 0) {
            n = abs(n);
            x = 1 / x;
        }
        
        return n & 1 ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
    }
};