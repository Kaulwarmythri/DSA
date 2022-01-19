class Solution {
public:
    int openLock(vector<string>& d, string target) {
        unordered_set<string> seen(d.begin(), d.end());
        if(seen.find("0000") != seen.end()) return -1;
        if(target == "0000") return 0;
        seen.insert("0000");
        
        queue<string> q({"0000"});
        int minTurns=0;
        while(q.size()){
            int s = q.size();
            minTurns++;
            for(int i=0; i<s; i++){
                auto curr = q.front(); q.pop();
                for(int i=0; i<4; i++){
                    for(auto adj : turn(curr, i)){
                        if(seen.find(adj)==seen.end()){
                            if(adj == target) return minTurns;
                            else q.push(adj), seen.insert(adj);
                        }
                    }
                }
            }
        }
        return -1;    
    }
    
    vector<string> turn(string s, int i){
        vector<string> ans(2, s);
        ans[0][i] = '0' + (ans[0][i] - '0' + 1)%10;
        ans[1][i] = '0' + (ans[1][i] - '0' - 1 + 10)%10;
        
        return ans;
    }
};