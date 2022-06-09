class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size(), i=0, buy, sell, profit = 0;
        
        while(i < n-1) {
            while(i < n-1 && p[i] >= p[i+1]) i++;
            buy = p[i];
            
            while(i < n-1 && p[i] <= p[i+1]) i++;
            sell = p[i];
            
            profit += sell - buy;
        }
        
        return profit;
    }
};