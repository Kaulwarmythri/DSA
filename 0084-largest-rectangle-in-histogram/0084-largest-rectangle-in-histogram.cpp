class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        int n = H.size(), i = 0, top = 0, area_with_top = 0, maxi = INT_MIN;
        stack<int> s;
        
        while(i < n) {
            if(s.empty() || H[s.top()] <= H[i]) s.push(i++);
            else {
                top = s.top(); s.pop();
                area_with_top = H[top] * (s.empty() ? i : i - s.top() -1);
                maxi = max(maxi, area_with_top);
            }
        }
        
        while(!s.empty()) {
            top = s.top(); s.pop();
            area_with_top = H[top] * (s.empty() ? i : i - s.top() - 1);
            maxi = max(maxi, area_with_top);
        }
        
        return maxi;
    }
};

//https://www.youtube.com/watch?v=jC_cWLy7jSI
