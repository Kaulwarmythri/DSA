class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(auto &ch : num){
            while(s.size() && s.top() > ch && k) s.pop(), k--;
            if(s.empty() && ch == '0') continue;
            else s.push(ch);
        }
        while(!s.empty() && k){
            s.pop();
            k--;
        }
        
        string ans = "";
        while(s.size()){
            ans = s.top() + ans;
            s.pop();
        }
        return ans.size() > 0 ? ans : "0";
    }
};


