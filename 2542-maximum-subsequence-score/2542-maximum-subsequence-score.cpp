class Solution {
public:
    long long maxScore(vector<int>& A, vector<int>& B, int k) {
        int n = A.size();
        vector<pair<int, int>> v;
        
        for(int i=0; i<n; i++) 
            v.push_back({B[i], A[i]});
        
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        long long sum = 0, ans = 0;
        
        for(auto &x: v) {
            pq.push(x.second);
            
            sum += x.second;
            if(pq.size() > k) {
                sum -= pq.top(); pq.pop();
            }
            
            if(pq.size() == k)
                ans = max(ans, sum * x.first);
        }
        return ans;
    }
};
