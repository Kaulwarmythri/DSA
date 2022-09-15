class Solution {
public:
    vector<int> findOriginalArray(vector<int>& A) {
        int n = A.size();
        if(n % 2)
            return {};
        unordered_map<int, int> m;
        for(auto &i: A) {
            m[i]++;
        }
        vector<int> keys;
        for(auto &it: m) {
            keys.push_back(it.first);
        }
        sort(keys.begin(), keys.end());
        
        vector<int> ans;
        for(auto &x: keys) {
            if(m[x] > m[x * 2]) 
                return {};
            for(int i=0; i<m[x]; i++, m[2*x]--) 
                ans.push_back(x);
        }
        
        return ans;
    }
};