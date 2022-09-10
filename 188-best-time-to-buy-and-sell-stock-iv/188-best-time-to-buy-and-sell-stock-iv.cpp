class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() <= 1 || k == 0) return 0;
        int n = prices.size();
        k = min(k, (int)(n/2));
        vector<int> buy(k, INT_MAX), profit(k, INT_MIN);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<k; j++) {
                if(!j) {
                    buy[j] = min(buy[j], prices[i]);
                } else {
                    buy[j] = min(buy[j], prices[i]-profit[j-1]);
                }
                profit[j] = max(profit[j], prices[i]-buy[j]);
            }
        }
        return profit[k-1];
    }
};