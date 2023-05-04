class Solution {
public:
    string predictPartyVictory(string S) {
        int n = S.size();
        
        queue<int> q1, q2;
        for(int i=0; i<n; i++)
            S[i] == 'R' ? q1.push(i) : q2.push(i);
            
        while(q1.size() && q2.size()) {
            auto i1 = q1.front(); auto i2 = q2.front();
            q1.pop(); q2.pop();
            
            (i1 < i2) ? q1.push(i1 + n) : q2.push(i2 + n);
        }
        return q1.size() ? "Radiant" : "Dire";
    }
};