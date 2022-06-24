class Solution {
public:
    int minRefuelStops(int X, int start, vector<vector<int>>& stns) {
        int n = stns.size(), curr = 0, ans = 0;
        
        priority_queue<int> pq;
        
        while(start < X) {
            while(curr < n && stns[curr][0] <= start) {
                pq.push(stns[curr][1]);
                curr++;
            }
            if(pq.empty()) return -1;
            start += pq.top(); pq.pop();
            ans++;
        }
        return ans;
    }
};

