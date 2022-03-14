class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        
        stack<string> s;
        
        istringstream X(path);
        
        string temp = "", ans = "";
        
        while(getline(X, temp, '/')) {
            if(temp == "" || temp == ".") continue;
            
            else if(temp == "..") {
                if(!s.empty()) s.pop();
            }
            else s.push(temp);
        }
        
        if(s.empty()) return "/";
        
        while(!s.empty()){
            ans = "/" + s.top() + ans;
            s.pop();
        }
        
        return ans;
        
        
    }
};


