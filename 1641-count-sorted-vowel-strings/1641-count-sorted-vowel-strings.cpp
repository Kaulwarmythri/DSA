class Solution {
public:
    int countVowelStrings(int n) {
        string curr = "";
        vector<string> ans;
        
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        solve(n, vowels, 0, curr, ans);
        
        return ans.size();
    }
    
    void solve(int n, vector<char>&vowels, int i, string &curr, vector<string> &ans) {
        if(curr.size() == n) {
            ans.push_back(curr);
            return;
        }
        
        for(int j=i; j<5; j++) {
            curr += vowels[j];
            solve(n, vowels, j, curr, ans);
            curr.pop_back();
        }
    }
};