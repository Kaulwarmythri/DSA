class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        
        if(k > n) return false;
        set<string> mySet;
        
        for(int i=0; i<=n-k; i++) {
            mySet.insert(s.substr(i, k));
        }
        
        return mySet.size() == pow(2, k);
    }
};