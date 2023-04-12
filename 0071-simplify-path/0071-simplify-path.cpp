class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        
        istringstream ss(path);
        string dir, ans;
        
        while(getline(ss, dir, '/')) {
            if(dir == "" || dir == ".") continue;
            else if(dir == "..") {
                if(!s.empty()) s.pop();
            }
            else s.push(dir);
        }
        
        if(s.empty()) return "/";
        while(s.size()) {
            dir = s.top(); s.pop();
            ans = "/" + dir + ans;
        }
        return ans;
    }
};