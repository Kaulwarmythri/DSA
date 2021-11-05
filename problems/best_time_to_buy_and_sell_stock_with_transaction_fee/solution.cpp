class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
	int maxProfitWithOneStock = -(prices[0] + fee);
	int maxProfitWithNoStock = 0;
	for (int i = 1; i < n; ++i) {
		maxProfitWithOneStock = max(maxProfitWithOneStock, maxProfitWithNoStock - prices[i] -         fee);
		maxProfitWithNoStock = max(maxProfitWithNoStock, maxProfitWithOneStock + prices[i]);
	}

	    return maxProfitWithNoStock;
    }
};