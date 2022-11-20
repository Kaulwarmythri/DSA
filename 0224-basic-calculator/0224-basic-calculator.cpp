class Solution {
public:
    int calculate(string str) {
        int n = str.size(), num = 0, sign = 1;
        long long sum = 0;
        
        stack<pair<int, int>> s;
        
        for(int i=0; i<n; i++) {
            if(isdigit(str[i])) {
                while(i < n && isdigit(str[i])) {
                    num = num * 10 + (str[i] - '0');
                    i++;
                }
                i--;
                sum += num * sign;
                num = 0;
                sign = 1;
            } else if(str[i] == '(') {
                s.push({sum, sign});
                sum = 0;
                sign = 1;
            } else if(str[i] == '-') {
                sign *= -1;
            } else if(str[i] == ')') {
                sum = s.top().first + s.top().second * sum;
                s.pop();
            } else continue;
        }
        return sum;
    }
};