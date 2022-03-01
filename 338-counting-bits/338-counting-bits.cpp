class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);
        int p = 1, pow = 1;
        for(int i=1;i<n+1;i++){
            if(i==pow){
                ans[i] = 1;
                pow <<= 1;
                p = 1;
            }else {
                ans[i] = ans[p] + 1;
                p++;
            }
        }
        return ans;
    }
};


/*class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0; i<=n; i++){
            ans[i] = __builtin_popcount(i);
        }
        return ans;
    }
};*/