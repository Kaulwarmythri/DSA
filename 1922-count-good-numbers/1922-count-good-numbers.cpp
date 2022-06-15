class Solution {
public:
    int countGoodNumbers(long long n) {
        int mod = 1000000007;
        return modPow(5, (n+1)/2, mod) * modPow(4, n/2, mod) % mod;
    }
    
    long long modPow(long long a, long long b, int mod) {
        if(b == 0) return 1;
        
        auto p = modPow(a, b/2, mod);
        
        return p * p * (b%2 ? a : 1) % mod;
    }
};