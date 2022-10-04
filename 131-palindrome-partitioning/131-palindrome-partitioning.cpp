class Solution {
    vector<vector<string>> ans;
public:
    vector<vector<string>> partition(string s) {
        vector<string> buff;
        find(s, 0, buff);
        
        return ans;
    }
    
    void find(string s, int i, vector<string> &buff) {
        if(i == s.size()) {
            ans.push_back(buff);
            return;
        }
        for(int j=i; j<s.size(); j++) {
            if(isPalindrome(s, i, j)) {
                buff.push_back(s.substr(i, j-i+1));
                find(s, j+1, buff);
                buff.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
};