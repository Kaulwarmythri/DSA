class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        
        int buy1 = INT_MAX, profit1 = INT_MIN, buy2 = INT_MAX, profit2 = INT_MIN;
        
        for(int i=0; i<n; i++) {
            buy1 = min(buy1, p[i]);
            profit1 = max(profit1, p[i] - buy1);
            
            buy2 = min(buy2, p[i] - profit1);
            profit2 = max(profit2, p[i] - buy2);
        }
        
        return profit2;
    }
};