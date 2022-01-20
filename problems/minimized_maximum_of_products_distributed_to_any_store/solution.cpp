class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quant) {
        int l=1, r=*max_element(quant.begin(), quant.end());
        
        while(l < r){
            int mid = l + (r-l)/2;
            if (canDistribute(quant, mid, n)) l = mid+1;
            else r = mid;
        }
        return l;
    }
    
    bool canDistribute(vector<int> quant, int max, int n){
        int count=0;
        for(auto x : quant){
            count += x/max;
            if(x%max) count++;
        }
        return count > n;
    }
};