class Solution {
public:
    int hammingDistance(int x, int y) {
        int xOR = x^y;
        return __builtin_popcount(xOR);
    }
};