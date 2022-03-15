class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size(), cnt = 0;
        string ans;
        
        for(int i=0; i<n; i++){
            if(s.at(i) == '(') cnt++;
            else if(s.at(i) == ')'){
                if(cnt == 0) s[i] = '#';
                else cnt--;
            }
        }
        cnt = 0;
        for(int i=n-1; i>=0; i--){
            if(s.at(i) == ')') cnt++;
            else if(s.at(i) == '('){
                if(cnt == 0) s[i] = '#';
                else cnt--;
            }
        }
        
        for(int i=0; i<n; i++) {
            if(s[i] != '#') ans.push_back(s[i]);
        }
        return ans;
    }
};