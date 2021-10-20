class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string word, res;
        vector<string> v;
        while(ss >> word){
            v.push_back(word);
        }
        
        reverse(v.begin(), v.end()); 
        
        for (const auto &p : v) 
            res += " " + p;
        
        res.erase(0,1);
        
        return res;
        
        
    }
};