class Solution {
public:
    int maxProfit(vector<int>& P) {
        int n = P.size(), buy = P[0], profit = 0;
        
        for(int i=1; i<n; i++) {
            if(P[i] < P[i-1]) 
                buy = min(buy, P[i]);
            else 
                profit = max(profit, P[i] - buy);
        }
        return profit;
    }
};