class Solution {
public:
    bool canPlaceFlowers(vector<int>& fb, int n) {
        int m = fb.size(), ans=0;
        
        for(int i=0; i<m; i++){
            if(fb[i]==0 && (i==0 || fb[i-1]!=1) && (i==m-1 || fb[i+1] != 1)){
                ans += 1;
                fb[i] = 1;
            }
        }
        return ans>=n ? true : false;
    }
};