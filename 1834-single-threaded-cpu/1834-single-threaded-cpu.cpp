class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& T) {
        int n = T.size();
        vector<int> ans;
        
        for(int i=0; i<n; i++)
            T[i].push_back(i);
        
        sort(T.begin(), T.end());
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        long long time = T[0][0]; int i = 0;
        
        while(i < n && T[i][0] <= time) pq.push({T[i][1], T[i][2]}), i++;
        
        while(pq.size()) {
            auto curr = pq.top(); pq.pop();
            
            time += curr.first;
            ans.push_back(curr.second);
            
            if(pq.empty()) {
                if(i < n) time = max(time, T[i][0]);
            }
            
            while(i < n && T[i][0] <= time) pq.push({T[i][1], T[i][2]}), i++;
        }
        return ans;
    }
    
    long long max(int a, long long b) {
        return a > b ? a : b;
    }
};