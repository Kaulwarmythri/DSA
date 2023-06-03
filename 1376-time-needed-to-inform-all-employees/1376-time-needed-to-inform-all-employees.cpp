class Solution {
public:
    int numOfMinutes(int n, int hid, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int> >m;
        
        for(int i=0;i<manager.size();i++) {
            m[manager[i]].push_back(i);
        }
        
        queue<pair<int,int>>q; q.push({hid, 0});
        int maxi=0;
        
        while(!q.empty()) {
            int s=q.size();
            while(s--) {
                auto [head, time] = q.front(); q.pop();
                int dur = informTime[head] + time;
                maxi = max(maxi, dur);
                for(auto &it: m[head]) {
                    q.push({it, dur});
                }
            }
        }
        return maxi;
    }
};