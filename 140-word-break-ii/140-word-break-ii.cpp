class Solution {
    vector<string> ans;
    string buff = "";
    int n;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        set<string> words(wordDict.begin(), wordDict.end());
        
        solve(s, 0, words, buff);
        return ans;
    }
    
    void solve(string s, int i, set<string> &words, string buff) {
        if(i==n) {
            buff.pop_back();
            ans.push_back(buff);
            return;
        }
        
        string str = "";
        for(int j=i; j<n; j++) {
            str += s[j];
            if(words.count(str)) {
                solve(s, j+1, words, buff+str+" ");
            }
        }
    }
};