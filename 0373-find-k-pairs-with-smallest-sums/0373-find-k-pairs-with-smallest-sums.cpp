class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k) {
        int m = A.size(), n = B.size();
        
        priority_queue<pair<int, pair<int, int>>> pq;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                int sum = A[i] + B[j];
                
                if(pq.size() < k) 
                    pq.push({sum, {A[i], B[j]}});
                else if(pq.top().first > sum) {
                    pq.pop();
                    pq.push({sum, {A[i], B[j]}});
                } else break;
            }
        }
        
        vector<vector<int>> ans;
        while(pq.size()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};