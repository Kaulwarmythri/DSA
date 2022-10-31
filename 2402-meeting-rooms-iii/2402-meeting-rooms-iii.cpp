#define pli pair<long long, int>
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& M) {
        sort(M.begin(), M.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });
        
        priority_queue<pli, vector<pli>, greater<pli>> engaged;
        priority_queue<int, vector<int>, greater<int>> free;
        
        for(int i=0; i<n; i++) free.push(i);
        
        vector<int> freq(n, 0);
        
        for(auto &x: M) {
            int s = x[0], e = x[1];
            while(engaged.size() && engaged.top().first <= s) {
                auto [eT, room] = engaged.top(); engaged.pop();
                free.push(room);
            }
            
            if(free.size()) {
                auto room = free.top(); free.pop();
                engaged.push({e, room});
                
                freq[abs(room)]++;
            } else {
                auto [eT, room] = engaged.top(); engaged.pop();
                engaged.push({eT + (e - s), room});
                
                freq[abs(room)]++;
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(freq[i] > freq[ans])
                ans = i;
        }
        return ans;
    }
};