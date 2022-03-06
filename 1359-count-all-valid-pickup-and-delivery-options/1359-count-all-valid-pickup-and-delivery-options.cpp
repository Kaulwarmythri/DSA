class Solution {
public:
    int countOrders(int n) {
        long long ans = 1, mod = 1000000007;
        
        for(int i=1; i<=n; i++){
            ans *= i*(2*i - 1);
            ans %= mod;
        }
        return ans%mod;
    }
};