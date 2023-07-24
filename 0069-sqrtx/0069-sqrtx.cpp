class Solution {
public:
    int mySqrt(int x) {
        if(!x) return x;
        
        int ans, l = 1, r = x;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(mid > x / mid) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid + 1;
            }
        }
        return ans;
    }
};