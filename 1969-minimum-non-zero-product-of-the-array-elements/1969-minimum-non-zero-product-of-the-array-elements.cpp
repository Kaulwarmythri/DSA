class Solution {
public:
    long long myPow(long long base, long long exp, int mod) {
        if (exp == 0) return 1;
        if (exp == 1) return base % mod;
        
        long long ans = myPow(base, exp/2, mod);
        
        return (((ans * ans) % mod) * ((exp % 2 ) ? (base % mod) : 1)) % mod;
    }
    
    int minNonZeroProduct(int p) {
        long long range = pow(2, p);
        range--;
        int mod = pow(10, 9) + 7;
        
        long long ans = myPow(range-1, range/2, mod);
        
        return (ans * (range%mod)) % mod;
    }
};



