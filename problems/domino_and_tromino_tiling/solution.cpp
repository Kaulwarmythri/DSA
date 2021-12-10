class Solution {
public:
    int numTilings(int n) {
        if(n<=2) return n;
        
        int mod = 1'000'000'007;
        vector<long> d(n+1, 0), t(n+1, 0);
        
        d[0]=0; d[1]=1; d[2]=2;
        t[0]=0; t[1]=1; t[2]=2;
        
        for(int i=3;i<=n;i++){
            d[i] = (d[i-1] + d[i-2] + 2*t[i-2]) % mod;
            t[i] = (t[i-1] + d[i-1]) % mod;
        }
        
        return d[n];
        
    }
};
