class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        
        int n = prices.size(), minPrice = prices[0], profit = 0;
        
        for(int i=1; i<n; i++) {
            if(prices[i] < prices[i-1]) minPrice = min(minPrice, prices[i]);
            else profit = max(profit, prices[i] - minPrice);
        }
        return profit;
    }
    
};