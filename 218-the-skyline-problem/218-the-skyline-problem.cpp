class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int curr = 0, curx, curh = -1, n = B.size();
        priority_queue<pair<int, int>> pq;
        
        while(curr < n || pq.size()) {
            curx = pq.empty() ? B[curr][0] : pq.top().second;
            if(curr >= n || B[curr][0] > curx) {
                while(pq.size() && pq.top().second <= curx) pq.pop();
            } else {
                curx = B[curr][0];
                while(curr < n && B[curr][0] == curx) {
                    pq.push({B[curr][2], B[curr][1]});
                    curr++;
                }
            }
            curh = pq.empty() ? 0 : pq.top().first;
            if(ans.empty() || ans.back()[1] != curh) ans.push_back({curx, curh});
        }
        
        return ans;
    }
};