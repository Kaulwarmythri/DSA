class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& w1, vector<string>& w2) {
        string s1 = "", s2 = "";
        for(auto w : w1) s1 += w;
        for(auto w : w2) s2 += w;
        
        return s1 == s2;
    }
};