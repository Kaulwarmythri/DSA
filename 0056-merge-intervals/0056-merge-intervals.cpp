class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& I) {
        vector<vector<int>> ans; 
        sort(I.begin(), I.end());
        int n = I.size(), prev = 0;
        ans.push_back(I[0]);
        
        for(int i=1; i<n; i++) {
            if(I[i][0] > ans[prev][1]) {
                ans.push_back(I[i]);
                prev++;
            }
            else {
                if(I[i][1] <= ans[prev][1]) continue;
                else ans[prev][1] = I[i][1];
            }
        }
        return ans;
    }
};