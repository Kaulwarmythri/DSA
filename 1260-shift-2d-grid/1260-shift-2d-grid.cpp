class Solution {
    void reverse(vector<int> &v, int start, int end) {
        while(start < end) {
            swap(v[start++], v[end--]);
        }
    }
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(), n=grid[0].size();
        
        vector<int> v;
        
        for(auto &i: grid) {
            for(auto &j: i) {
                v.push_back(j);
            }
        }
        
        k = k%v.size();
        reverse(v, 0, v.size()-k-1);
        reverse(v, v.size()-k, v.size()-1);
        reverse(v, 0, v.size()-1);
        
        int vec = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
               grid[i][j] = v[vec];
                vec++;
            }
        }
        return grid;
    }
};