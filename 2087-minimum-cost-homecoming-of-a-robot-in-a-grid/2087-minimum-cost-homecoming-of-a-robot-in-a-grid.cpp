class Solution {
public:
    int minCost(vector<int>& s, vector<int>& h, vector<int>& rowC, vector<int>& colC) {
        int ans = 0;
        for(int i=h[0]; i!=s[0]; i+=h[0] > s[0] ? -1 : 1) 
            ans += rowC[i];
        for(int j=h[1]; j!=s[1]; j+=h[1] > s[1] ? -1 : 1) 
            ans += colC[j];
        
        return ans;
    }
};