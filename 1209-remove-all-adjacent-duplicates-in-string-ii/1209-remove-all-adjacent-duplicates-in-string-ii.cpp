class Solution {
public:
    string removeDuplicates(string str, int k) {
        int n = str.size();
        if(k > n) return str;
        
        stack<pair<char,int>> s;
        
        for(int i=0; i<n; ++i){
            
            if(s.empty() || s.top().first != str[i]) s.push({str[i],1});
            
            else {
                auto prev = s.top(); s.pop();
                s.push({str[i], prev.second+1});
            }
            if(s.top().second == k) s.pop();
        }
        
        string ans = "";
        while(!s.empty()){
            auto cur = s.top(); s.pop();
            
            while(cur.second--)
                ans.push_back(cur.first);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


