class Solution {
public:
    int maxProfit(vector<int>& P) {
        int n = P.size(), max_profit = 0, min_price = P[0];
        
        for(int i=1; i<n; i++) {
            if(P[i] > P[i-1]) max_profit = max(max_profit, P[i] - min_price);
            else min_price = min(min_price, P[i]);
        }
        
        return max_profit;
    }
};