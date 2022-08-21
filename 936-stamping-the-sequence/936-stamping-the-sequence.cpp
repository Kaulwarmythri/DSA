class Solution {
    int m, n, stars;
    vector<int> ans;
public:
    vector<int> movesToStamp(string stamp, string target) {
        m = stamp.size(), n = target.size(), stars = 0;
        vector<bool> vis(n, false);
        
        while(stars < n) {
            bool replaced = false;
            
            for(int i=0; i<=n-m && stars < n; i++) {
                if(!vis[i]) replaced = checkAndReplace(i, stamp, target);
                vis[i] = replaced;
            }
            if(!replaced) return {};
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    bool checkAndReplace(int &start, string &stamp, string &target) {
        for(int i=0; i<m; i++) {
            if(target[start+i] != '*' && target[start+i] != stamp[i]) return false;
        }
        ans.push_back(start);
        
        for(int i=start; i-start < m; i++) {
            stars += (target[i] != '*');
            target[i] = '*';
        }
        return true;
    }
};