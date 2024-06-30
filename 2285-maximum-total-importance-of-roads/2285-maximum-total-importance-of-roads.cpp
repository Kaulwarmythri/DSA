class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& R) {
        long long ans = 0, imp = 1;
        
        vector<int> degree(n, 0);
        
        for(auto &r: R) {
            degree[r[0]]++;
            degree[r[1]]++;
        }
        
        sort(degree.begin(), degree.end());
        
        for(auto &d: degree) 
            ans += d * (imp++);
        
        return ans;
    }
};