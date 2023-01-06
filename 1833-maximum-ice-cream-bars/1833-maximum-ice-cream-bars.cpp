class Solution {
public:
    int maxIceCream(vector<int>& C, int coins) {
        int n = C.size();
        sort(C.begin(), C.end());
        
        for(int i=0; i<n; i++) {
            if(C[i] <= coins) coins -= C[i];
            else return i;
        }
        return n;
    }
};