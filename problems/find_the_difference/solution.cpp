class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> m;
        for(auto &x : s) m[x]++;
        
        for(auto &p : t){
            if(m[p]==0) return p;
            m[p]--;
        }
        return '\0';
    }
};