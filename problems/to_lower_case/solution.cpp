class Solution {
public:
    string toLowerCase(string s) {
        for(auto &x : s) if(isupper(x)) x = tolower(x);
        
        return s;
    }
};