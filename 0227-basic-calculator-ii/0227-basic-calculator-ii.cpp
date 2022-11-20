class Solution {
public:
    int calculate(string str) {
        long long sum = 0, num = 0;
        char op = '+';
        
        istringstream ss(str);
        stack<int> s;
        
        while(ss >> num) {
            if(op == '+' || op == '-') {
                s.push(op == '+' ? num : -num);
            } else {
                if(op == '*') {
                    num *= s.top(); s.pop();
                    s.push(num);
                } else {
                    num = s.top() / num; s.pop();
                    s.push(num);
                }
            }
            ss >> op;
        }
        
        while(s.size()) {
            sum += s.top(); s.pop();
        }
        return sum;
    }
};