class Solution {
public:
    int maxProfit(vector<int>& P) {
        int l = 0, r = 1, maxProfit = 0;
        
        while(r < P.size()) {
            if(P[l] < P[r]) maxProfit = max(maxProfit, P[r] - P[l]);
            else if(P[r] < P[l]) l = r;
            r++;
        }
        return maxProfit;
    }
};