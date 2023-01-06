class Solution {
public:
    int maxIceCream(vector<int>& C, int coins) {
        int n = C.size(), ans = 0;
        sort(C.begin(), C.end());
        
        for(int i=0; i<n; i++) {
            if(C[i] <= coins) ans++, coins -= C[i];
            else break;
        }
        return ans;
    }
};