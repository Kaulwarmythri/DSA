class Solution {
public:
    int minNonZeroProduct(int p) {
        long long range = pow(2, p);
        int mod = 1e9+7;
        range--;
        
        long long ans = modpow(range-1, range / 2, mod);
        return ans * (range % mod) % mod;
    }
    
    long long modpow(long long a, long long b, int mod) {
        if(!b) return 1;
        if(b == 1) return a % mod;
        auto p = modpow(a, b/2, mod);
        return (p * p) % mod * (b % 2 ? a % mod : 1) % mod;
    }
};



