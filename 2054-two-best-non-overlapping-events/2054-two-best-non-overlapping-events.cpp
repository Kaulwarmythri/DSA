#define pii pair<int, int>
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int ans = 0, maxsofar = 0;
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        
        for(auto &e: events) {
            while(!pq.empty() && pq.top().first < e[0]) {
                auto curr = pq.top(); pq.pop();
                maxsofar = max(maxsofar, curr.second);   
            }
            ans = max(ans, maxsofar + e[2]);
            pq.push({e[1], e[2]});
        }
        return ans;
    }
};