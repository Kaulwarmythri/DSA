class Solution {
public:
    string decodeString(string str) {
        stack<char> s;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ']') s.push(str[i]);
        else{
            string temp;
            while (!s.empty() && s.top() != '[') temp = s.top() + temp, s.pop();
            
            s.pop();
            
            string num;
            while (!s.empty() && isdigit(s.top())) num = s.top() + num, s.pop();
            int number = stoi(num);
            
            string repeat;
            for (int j = 0; j < number; j++) repeat += temp;
            for (auto c : repeat) s.push(c);
        }
    }
    string ans;
    while (!s.empty()) ans = s.top() + ans, s.pop();
        
    return ans;
        
    }
};