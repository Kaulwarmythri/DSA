class Solution {
public:
    int trap(vector<int>& height) {
        int l=0, r=height.size()-1, l_max=0, r_max=0, res=0;
        
        while(l<r){
            r_max = max(r_max, height[r]);
            res+=r_max-height[r];
            
            l_max = max(l_max, height[l]);
            res+=l_max-height[l];
            
            if(height[l]<=height[r]) l++;
            else r--;
        }
        return res;
    }
};