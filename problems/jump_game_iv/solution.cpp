class Solution {
public:
    int minJumps(vector<int>& a) {
        int n = a.size(), jumps=0;
        if(n==1) return 0;
        unordered_map<int, vector<int>> m;
        for(int i=0; i<n; i++) m[a[i]].push_back(i);
        
        queue<int> q;
        q.push(0);
        while(q.size()){
            jumps++;
            int size = q.size();
            while(size--){
                int curr = q.front(); q.pop();
                if(curr-1 >= 0 && m.find(a[curr-1]) != m.end()) q.push(curr-1);
                if(curr+1 < n && m.find(a[curr+1]) != m.end()){
                    if(curr+1 == n-1) return jumps;
                    q.push(curr+1);
                }
                if(m.find(a[curr]) != m.end()){
                    for(auto k : m[a[curr]]){
                        if(k != curr){ if(k==n-1) return jumps; q.push(k); }
                    }
                }
                m.erase(a[curr]);
            }
        }
        return jumps;
    }
};


