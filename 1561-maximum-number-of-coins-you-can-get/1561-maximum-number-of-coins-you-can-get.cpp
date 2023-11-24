class Solution {
public:
    int maxCoins(vector<int>& P) {
        sort(P.begin(), P.end());
        
        int n = P.size(), ans = 0;
        
        for(int i = n/3; i<n; i+=2)
            ans += P[i];
        
        return ans;
    }
};