class Solution {
public:
    int maxSatisfaction(vector<int>& S) {
        sort(S.begin(), S.end());
        int n = S.size();
        
        int Cumulative_sum = 0; // From back
        
        int ans = 0;
        int cur = 0;
        for(int i = n-1;i>=0;i--)
        {
            cur += Cumulative_sum + S[i];
            Cumulative_sum += S[i];
            
            ans = max(ans, cur);
        }
        
        return ans;
    }
};