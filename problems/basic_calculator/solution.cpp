class Solution {
public:
    int calculate(string s) {
        stack<pair<int, int>> stk;
        long long int sum = 0, num = 0;
        int  sign = 1;
        
        for(int i=0; i<s.size(); i++){
            if(isdigit(s[i])){
                
                while(i < s.size() && isdigit(s[i])){
                    num = num*10 + (s[i] - '0');
                    i++;
                } 
                i--;
                sum += num*sign;
                sign = 1;
                num = 0;
            }
            else if(s[i] == '('){
                stk.push(make_pair(sum, sign));
                
                sum = 0;
                sign = 1;
            
            }else if(s[i] == '+'){ 
                sign = 1;
            }else if(s[i] == '-'){
                sign = sign*(-1);
            }else if(s[i] == ')'){
                sum = stk.top().first + (stk.top().second)*sum;
                stk.pop();
                
            }else continue;
        }
        
        return sum;
    }
};


