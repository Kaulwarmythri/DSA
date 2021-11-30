class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m=matrix.size(), n=matrix[0].size(), ans=0;
        vector<int> dp(n, 0);
        
        for(int j=n-1; j>=0; j--) dp[j] = matrix[m-1][j] - '0';
        ans = largestRectangleArea(dp);
            
        for(int i=m-2; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                dp[j] = matrix[i][j] == '0' ? 0 : dp[j]+1;
            }
            ans = max(ans, largestRectangleArea(dp));
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& v) {
        int maxArea=INT_MIN, currArea, top=0, i=0, n=v.size();
        stack<int> s;
        
        while(i<n){
            if(s.empty() || v[s.top()]<=v[i]) s.push(i++);
            else{
                top = s.top(); s.pop();
                currArea = v[top]*(s.empty() ? i : i-s.top()-1);
                maxArea = max(maxArea, currArea);
            }
        }
        while(!s.empty()){
            top = s.top(); s.pop();
            currArea = v[top]*(s.empty() ? i : i-s.top()-1);
            maxArea = max(maxArea, currArea);
        } 
        return maxArea;
    }  
};