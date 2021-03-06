class Solution {
    map<int, string> m;
    
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits == "") return ans;
        
        m.insert({2, "abc"});
        m.insert({3, "def"});
        m.insert({4, "ghi"});
        m.insert({5, "jkl"});
        m.insert({6, "mno"});
        m.insert({7, "pqrs"});
        m.insert({8, "tuv"});
        m.insert({9, "wxyz"});
        
        string currString = "";
        makeCombinations(digits, currString, ans, 0);
        
        return ans;
    }
    
    void makeCombinations(string digits, string &curr, vector<string> &ans, int i) {
        
        if(i == digits.size()) {
            
            ans.push_back(curr);
            return;    
        }
        
        for(auto l : m[digits[i] - '0']) {
            curr += l;
            makeCombinations(digits, curr, ans, i+1);
            curr.pop_back();
        }
        
    }
};