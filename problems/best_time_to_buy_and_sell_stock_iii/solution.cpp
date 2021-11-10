class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1=INT_MAX, profit1=0, buy2=INT_MAX, profit2=0;
        
        for(int i=0;i<prices.size();i++){
            buy1 = min(buy1, prices[i]);  //buy on the day the price is the most minimum
            profit1 = max(profit1, prices[i]-buy1); //sell to make max profit
            
            buy2 = min(buy2, prices[i]-profit1); //buy with the profit you have on 1st                                                          //purchase
            profit2 = max(profit2, prices[i]-buy2); //sell to make up for any loss and make                                                       //max-profit again
        }
        return profit2;
    }
};