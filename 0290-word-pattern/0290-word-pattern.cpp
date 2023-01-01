class Solution {
public:
    bool wordPattern(string p, string s) {
        int n = p.size();
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        
        stringstream ss(s); 
        string word; int i = 0;
        
        for(; ss>>word; i++) {
            if(i == n || p2i[p[i]] != w2i[word])
                return false;
            
            p2i[p[i]]= i+1;
            w2i[word] = i+1;
        }
        return i == n;
    }
};