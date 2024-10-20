class Solution {
public:
    bool parseBoolExpr(string s) {
        int n = s.size();
        stack<char> st;
        for (auto& x : s) {
            if (x == ',')
                continue;
            else if (x == ')') {
                bool trackor = false, trackand = true,
                     tracknot = st.top() == 't' ? false : true;
                while (st.top() != '(') {
                    if (st.top() == 'f')
                        trackand = false;
                    else
                        trackor = true;
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                if (op == '|') {
                    st.push(trackor ? 't' : 'f');
                } else if (op == '&') {
                    st.push(trackand ? 't' : 'f');
                } else
                    st.push(tracknot ? 't' : 'f');
            } else
                st.push(x);
        }
        return st.top() == 't' ? true : false;
    }
};