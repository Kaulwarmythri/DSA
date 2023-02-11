#define MAX 1e5
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n,vector<vector<int>>& R,vector<vector<int>>& B) {
        vector<vector<pair<int, int>>> G(n);
        
        for(auto &e: R) 
            G[e[0]].push_back({e[1], 1});
        
        for(auto &e: B)
            G[e[0]].push_back({e[1], -1});
        
        vector<int> dR(n, MAX), dB(n, MAX);
        dR[0] = 0; dB[0] = 0;
        
        queue<int> q; q.push(0);
        
        while(q.size()) {
            auto cur = q.front(); q.pop();
            
            for(auto [child, color]: G[cur]) {
                if(color == 1 && dB[cur] + 1 < dR[child]) {
                    dR[child] = dB[cur] + 1;
                    q.push(child);
                } else if(color == -1 && dR[cur] + 1 < dB[child]) {
                    dB[child] = dR[cur] + 1;
                    q.push(child);
                }
            }
        }
        vector<int> ans(n, 0);
        
        for(int i=1; i<n; i++) 
            ans[i] = min(dR[i], dB[i]) == MAX ? -1 : min(dR[i], dB[i]);
        
        return ans;
        
    }
};