class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> s;
        int ans = INT_MIN, area_with_top = 0, top = 0, i = 0;
        
        while(i < h.size()){
            if(s.empty() || h[s.top()] <= h[i]) s.push(i++);
            else{
                top = s.top(); s.pop();
                area_with_top = h[top]*(s.empty() ? i : (i-s.top()-1));
                ans = max(ans, area_with_top);
            }
        }
        while(!s.empty()){
            top = s.top(); s.pop();
            area_with_top = h[top]*(s.empty() ? i : i-s.top()-1);
            ans = max(ans, area_with_top);
        }
        return ans;
    }
};