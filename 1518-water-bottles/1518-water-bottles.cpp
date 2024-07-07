class Solution {
public:
    int numWaterBottles(int n, int e) {
        int ans = n;
        
        while(n >= e) {
            int rem = n % e;
            ans += n / e;
            n /= e;
            n += rem;
        }
        return ans;
    }
};