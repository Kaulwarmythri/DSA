class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        
        vector<int> last_idx(26, 0);
        
        for(int i=0; i<n; i++) last_idx[s[i]-'a'] = i;  
        
        int start = 0, end = 0;
        
        for(int i=0; i<n; i++){
            end = max(end, last_idx[s[i]-'a']);
            
            if(i == end) {
                ans.push_back(i-start+1);
                start = i+1;
            }
        }
        
        return ans;
    }
};