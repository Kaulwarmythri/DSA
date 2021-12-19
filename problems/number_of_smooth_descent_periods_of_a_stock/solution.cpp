class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0; 
        for (int i = 0, cnt = 0; i < prices.size(); ++i) {
            if (i && prices[i-1] != prices[i]+1) cnt = 0; 
            ans += ++cnt; 
        }
        return ans; 
    }
};