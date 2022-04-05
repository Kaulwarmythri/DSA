class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(), l =0, r = n-1, maxi = 0;
        
        while(l < r) {
            
            int area = min(heights[l], heights[r])*(r-l);
            
            maxi = max(area, maxi);
            
            if(heights[l] < heights[r]) l++;
            
            else if(heights[r] < heights[l]) r--;
            
            else {
                l++;
                r--;
            }
            
        }
        return maxi;
    }
};