class Solution {
public:
    int minCost(string colors, vector<int>& times) {
        int n = colors.size(), sum_cost = 0, max_cost = 0, ans = 0;
        
        for(int i=0; i<n; i++) {
            if(i > 0 && colors[i] != colors[i-1]) {
                ans += sum_cost - max_cost;
                sum_cost = max_cost = 0;
            }
            sum_cost += times[i];
            max_cost = max(max_cost, times[i]);
        }
        ans += sum_cost - max_cost;
        return ans;
    }
};