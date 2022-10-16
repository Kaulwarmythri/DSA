class Solution {
    int m, n;
public:
    int maximalRectangle(vector<vector<char>>& M) {
        m = M.size(), n = M[0].size(); int maxi = INT_MIN;
        vector<int> hist(n, 0);
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(M[i][j] == '1') hist[j]++;
                else hist[j] = 0;
            }
            maxi = max(maxi, calcArea(hist, n));
        }
        return maxi;
    }
    
    int calcArea(vector<int> &hist, int n) {
        int i = 0, top = 0, area_with_top = 0, maxarea = INT_MIN;
        stack<int> s;
        while(i < n) {
            if(s.empty() || hist[s.top()] <= hist[i]) s.push(i++);
            else {
                top = s.top(); s.pop();
                area_with_top = hist[top] * (s.empty() ? i : i - s.top() - 1);
                maxarea = max(maxarea, area_with_top);
            }
        }
        
        while(!s.empty()) {
            top = s.top(); s.pop();
            area_with_top = hist[top] * (s.empty() ? i : i - s.top() - 1);
            maxarea = max(maxarea, area_with_top);
        }
        return maxarea;
    }
};