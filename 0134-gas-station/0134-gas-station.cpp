class Solution {
public:
    int canCompleteCircuit(vector<int>& G, vector<int>& C) {
        int n = G.size(), total_gas = 0, curr_gas = 0, ans = 0;
        
        for(int i=0; i<n; i++) {
            total_gas += G[i] - C[i];
            curr_gas += G[i] - C[i];
            
            if(curr_gas < 0) {
                curr_gas = 0;
                ans = i+1;
            }
        }
        return total_gas < 0 ? -1 : ans;
    }
};