class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& newIn) {
        int n = in.size(), i = 0;
        vector<vector<int>> ans;
        
        while(i < n && in[i][0] < newIn[0] && in[i][1] < newIn[0]) ans.push_back(in[i++]);
        while(i < n && in[i][0] <= newIn[1]) {
            newIn[0] = min(in[i][0], newIn[0]);
            newIn[1] = max(in[i][1], newIn[1]);
            i++;
        }
        ans.push_back(newIn);
        while(i < n) ans.push_back(in[i++]);
        
        return ans;
    }
};

