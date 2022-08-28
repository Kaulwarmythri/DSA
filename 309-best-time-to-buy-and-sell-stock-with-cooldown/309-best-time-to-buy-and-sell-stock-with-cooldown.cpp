class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int n = prices.size(), buy, sell, profit = 0, i = 0;
        while(i < n-1) {
            while(i < n-1 && prices[i] >= prices[i+1]) i++;
            buy = prices[i];
            while(i < n-1 && prices[i] <= prices[i+1]) i++;
            sell = prices[i];
            profit += sell - buy;
        }
        return profit;
    }
};
