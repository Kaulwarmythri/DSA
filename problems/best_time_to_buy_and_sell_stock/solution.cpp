class Solution {
public:
    int maxProfit(vector<int>& p) {
        if(p.size() < 2) return 0;
        
        int maxProfit = 0, minPrice = p[0];
        
        for(int i=1; i<p.size(); i++){
            if(p[i] > p[i-1]) maxProfit = max(maxProfit, p[i]-minPrice);
            
            else minPrice = min(minPrice, p[i]);
        }
        return maxProfit;
        
    }
};