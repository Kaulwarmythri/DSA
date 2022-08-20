class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        int a = 1;
        for (int i = 0; i < n; i+=2) {
            if (i == n-1) {
                ans[i] = 0;
                return ans;
            }
                
            ans[i] = a;
            ans[i+1] = -a;
            a++;
        }
        return ans;
    }
};