class Solution {
    int n;
    vector<string> ans;
public:
    vector<string> wordBreak(string A, vector<string>& words) {
        n = A.size();
        set<string> s(words.begin(), words.end());
        string buff = "";
        
        solve(A, s, 0, buff);;
        return ans;
    }
    
    void solve(string A, set<string> &s, int i, string buff) {
        if(i == n) {
            buff.pop_back();
            ans.push_back(buff);
            return;
        }
        
        string str = "";
        for(int j=i; j<n; j++) {
            str += A[j];
            if(s.count(str))
                solve(A, s, j+1, buff+str+" ");
        }
    }
};