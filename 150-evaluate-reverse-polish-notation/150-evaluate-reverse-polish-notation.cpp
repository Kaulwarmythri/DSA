class Solution {
public:
    int evalRPN(vector<string>& tk) {
        int n =tk.size(), i = 0;
        
        if(n < 2) return stoi(tk[0]);
        
        stack<int> s;
        
        while(i < n) {
            while(tk[i].size() > 1 || isdigit(tk[i][0])) s.push(stoi(tk[i++]));
            
            string op;
            if(i < n) op = tk[i++];
            auto first = s.top(); s.pop(); auto sec = s.top(); s.pop();
            
            if(op == "+") 
                s.push(sec + first);
            else if(op == "-") 
                s.push(sec - first);
            else if(op == "*") 
                s.push(sec * first);
            else if(op == "/")
                s.push(sec / first);
        }
        return s.top();
    }
};