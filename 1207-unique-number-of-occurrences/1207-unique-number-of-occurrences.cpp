class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        
        for(auto &i: arr) m[i]++;
        
        unordered_set<int> s;
        for(auto &x: m) if(!s.insert(x.second).second) return false;
        return true;
    }
};