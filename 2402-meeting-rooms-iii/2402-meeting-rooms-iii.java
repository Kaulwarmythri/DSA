#define pli pair<long long, int>
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& M) {
        vector<int> freqs(n, 0);
        sort(M.begin(), M.end());
        
        priority_queue<pli, vector<pli>, greater<pli>> engaged;
        priority_queue<int, vector<int>, greater<int>> free;
        
        for(int i=0; i<n; i++)
            free.push(i);
        
        for(auto &X: M) {
            int s = X[0], e = X[1];
            while(engaged.size() && engaged.top().first <= s) {
                auto [et, room] = engaged.top(); engaged.pop();
                free.push(room);
            }
            
            if(free.size()) {
                auto room = free.top(); free.pop();
                engaged.push({e, room});
                freqs[room]++;
                
            } else {
                auto [et, room] = engaged.top(); engaged.pop();
                engaged.push({et + (e - s), room});
                
                freqs[room]++;
            }
            
        }
        
        return max_element(freqs.begin(), freqs.end()) - freqs.begin();
        
    } 
};