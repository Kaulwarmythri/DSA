class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& P, vector<int>& C) {
        int n = P.size();
        vector<pair<int, int>> A;
        
        for(int i=0; i<n; i++) 
            A.push_back({C[i], P[i]});
        
        sort(A.begin(), A.end());
        
        int i = 0;
        priority_queue<int> pq; 
        while(k--) {
            while(i < n && A[i].first <= w) {
                pq.push(A[i].second);
                i++;
            }
            if(pq.empty()) break;
            w += pq.top(); pq.pop();
        }
        return w;
    }
};