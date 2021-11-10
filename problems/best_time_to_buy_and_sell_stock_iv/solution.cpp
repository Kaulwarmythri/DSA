class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        k=min(k, (int)prices.size()/2);
        
        vector<int> buy(k, INT_MAX), profit(k, 0);
        
        for(int i=0;i<prices.size();i++){
            
            for(int j=0;j<k;++j){
                if(j) buy[j] = min(buy[j], prices[i]-profit[j-1]);
                else  buy[j] = min(buy[j], prices[i]); 
                
                profit[j]=max(profit[j], prices[i]-buy[j]);
            }
        }
        return k && prices.size() ? profit.back() : 0;
    }
};

