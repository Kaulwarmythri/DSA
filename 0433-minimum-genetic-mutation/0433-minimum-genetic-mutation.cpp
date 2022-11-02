class Solution {
public:
    int minMutation(string start, string end, vector<string>& B) {
        int n = B.size();
        unordered_set<string> s(B.begin(), B.end()); 
        vector<char> genes = {'A', 'C', 'G', 'T'};
        if(!s.count(end)) return -1;
        
        queue<string> q; q.push(start);
        int ans = 0;
        
        while(q.size()) {
            int size = q.size();
            ans++;
            while(size--) {
                auto curr = q.front(); q.pop();
                if(curr == end) return ans;
                
                for(int i=0; i<8; i++) {
                    string temp = curr;
                    for(auto &c: genes) {
                        temp[i] = c;
                        if(temp == end) 
                            return ans;
                        if(temp == curr) 
                            continue;
                        if(s.count(temp)) {
                            q.push(temp);
                            s.erase(temp);
                        }
                    }
                }
            }
        }
        return -1;
    }
};