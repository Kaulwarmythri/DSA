class Solution {
public:
    int concatenatedBinary(int n) {
        long int ans = 0;
        int currlen = 0, mod = 1e9+7;
        
        for(int i=1; i<=n; i++) {
            if((i & (i-1)) == 0) currlen++;    //at every power of 2 len of binary increases
            
            ans = (ans << currlen) % mod;
            
            ans += i % mod;
        }
        return ans;
    }
};