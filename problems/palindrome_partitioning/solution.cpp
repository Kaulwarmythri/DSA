class Solution {
public:
    vector<vector<string>> ans;
    vector<string> buff;
    vector<vector<int>> dp;
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));
        find(s, 0);
        return ans;
    }
    
    void find(string s, int i){
        if(i==s.size()){
            ans.push_back(buff);
            return;
        }
        
        for(int j=i; j<s.size(); j++){
            if(isPalindrome(s, i, j)){
                buff.push_back(s.substr(i, j-i+1));
                find(s, j+1);
                buff.pop_back();
            }
        }   
    }
    
    bool isPalindrome(string s, int start, int end){
        if(dp[start][end] != -1) return dp[start][end];
        while(start < end){
            if(s[start] != s[end]) return dp[start][end] = false;
            start++;
            end--;
        }
        
        return dp[start][end] = true;
    }
};


