class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> ans;
        
        for(auto x : ops) {
            if(x == "D") ans.push_back(ans.back()*2);
            
            else if(x == "C") ans.pop_back();
            
            else if(x == "+") ans.push_back(ans.back()+ans[ans.size()-2]);
            
            else ans.push_back(stoi(x));
        }
       
        return accumulate(ans.begin(), ans.end(), 0);
    }
};