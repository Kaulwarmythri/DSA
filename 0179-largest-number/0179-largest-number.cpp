class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> A;
        
        for(auto &i: nums) 
            A.push_back(to_string(i));
        sort(A.begin(), A.end(), [](string &a, string &b) {
            return a+b > b+a;
        });
        
        string ans = "";
        for(auto &i: A) ans += i;
        
        while(ans[0] == '0' && ans.size() > 1) ans.erase(0, 1);
        return ans;
        
    }
};