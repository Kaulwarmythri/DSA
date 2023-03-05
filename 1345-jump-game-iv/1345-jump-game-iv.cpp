class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size(), jumps = 0;
        
        if(n == 1) return 0;
        unordered_map<int, vector<int>> m;
        
        for(int i=0; i<n; i++) 
            m[arr[i]].push_back(i);
        
        queue<int> q; q.push(0);
        
        while(!q.empty()) {
            int s = q.size();
            jumps++;
            
            while(s--) {
                auto i = q.front(); q.pop();
                if(i - 1 >= 0 && m.find(arr[i-1]) != m.end()) 
                    q.push(i - 1);
                
                if(i + 1 < n && m.find(arr[i+1]) != m.end()) {
                    if(i + 1 == n - 1) return jumps;
                    q.push(i + 1);
                }
                
                if(m.find(arr[i]) != m.end()) {
                    for(auto &x: m[arr[i]]) {
                        if(x != i) {
                            if(x == n-1) return jumps;

                            q.push(x);
                        }
                     }
                }
                m.erase(arr[i]);
            }
        }
        return jumps;
    }
};




