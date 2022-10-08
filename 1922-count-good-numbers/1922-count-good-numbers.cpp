class Solution {
public:
    int countGoodNumbers(long long n) {
        int mod = 1e9 + 7;
        return modpow(5, (n+1)/2, mod) * modpow(4, n/2, mod) % mod;
    }
    
    long long modpow(long long a, long long b, int mod) {
        if(!b) return 1;
        
        auto p = modpow(a, b/2, mod);
        return p * p * (b%2 ? a : 1) % mod;
    } 
};