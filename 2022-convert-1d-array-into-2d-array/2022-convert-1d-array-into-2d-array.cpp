class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m * n) return {};
        
        vector<vector<int>> ans;
        
        for(int i=0; i<m*n;) {
            vector<int> temp;
            for(int j=0; j<n; j++) temp.push_back(original[i++]);
            ans.push_back(temp);
        }
        return ans; 
    }
};