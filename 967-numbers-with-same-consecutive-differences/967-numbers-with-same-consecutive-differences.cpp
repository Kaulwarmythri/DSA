class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        
        for(auto num=1; num<=9; num++) {
            dfs(num, n-1, k, ans);
        }
        return ans;
    }
    
    void dfs(int num, int n, int k, vector<int> &ans) {
        if(n == 0) {
            ans.push_back(num);
        } else {
            int dig = num % 10;
            if(dig + k <= 9) {
                dfs(num * 10 + dig + k, n-1, k, ans);
            }
            if(k != 0 && dig >= k) {
                dfs(num * 10 + dig - k, n-1, k, ans);
            }
        }
    }
};