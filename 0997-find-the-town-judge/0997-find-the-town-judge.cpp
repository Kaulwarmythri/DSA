class Solution {
public:
    int findJudge(int n, vector<vector<int>>& T) {
        vector<int> inout(n, 0);
        
        for(auto &t: T) {
            inout[t[0] - 1]--;
            inout[t[1] - 1]++;
        }
        
        for(int i=0; i<n; i++) 
            if(inout[i] == n-1) return i+1;
        
        return -1;
    }
};