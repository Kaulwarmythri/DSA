class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int d = chebyshev(sx, sy, fx, fy);
        
        return d > 0 ? t >= d : t != 1;
    }
    
    int chebyshev(int sx, int sy, int fx, int fy) {
        return max(abs(sx - fx), abs(sy - fy));
    }
};