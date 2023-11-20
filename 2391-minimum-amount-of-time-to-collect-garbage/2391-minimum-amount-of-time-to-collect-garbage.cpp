class Solution {
public:
    int garbageCollection(vector<string>& G, vector<int>& T) {
        int n = G.size(), ans = 0;
        bool hasP = false, hasG = false, hasM = false;
        
        for(int i=n-1; i>=0; i--) {
            if(!hasP && G[i].find('P') != string::npos) {
                hasP = true;
                ans += accumulate(T.begin(), T.begin() + i, 0);
            }
            
            if(!hasG && G[i].find('G') != string::npos) {
                hasG = true;
                ans += accumulate(T.begin(), T.begin() + i, 0);
            }
            
            if(!hasM && G[i].find('M') != string::npos) {
                hasM = true;
                ans += accumulate(T.begin(), T.begin() + i, 0);
            }
            
            if(hasP && hasG && hasM)
                break;
        }
        
        ans += accumulate(G.begin(), G.end(), 0, [](int sum, string &s) {
            return sum + s.size();
        });
        
        return ans;
    }
};