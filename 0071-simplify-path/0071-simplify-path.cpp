class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        
        istringstream ss(path);
        string temp, ans = "";
        
        while(getline(ss, temp, '/')) {
            if(temp == "" || temp == ".") continue;
            else if(temp == "..") {
                if(!s.empty()) s.pop();
            }
            else s.push(temp);
        }
        
        if(s.empty()) return "/";
        while(s.size()) {
            auto curr = s.top(); s.pop();
            ans = "/" + curr + ans;
        }
        return ans;
    }
};