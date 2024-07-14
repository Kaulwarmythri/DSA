class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<pair<string, int>> st;

        for (int i = 0; i < n; i++) {
            char ch = formula[i];
            if (isupper(ch)) {
                string temp = "";
                temp += ch;
                int j = i + 1;
                while (j < n && islower(formula[j])) {
                    temp += formula[j];
                    j++;
                }
                
                string dig = "";
                while (j < n && isdigit(formula[j])) {
                    dig += formula[j];
                    j++;
                }
                if (dig == "") dig = "1";
                int digit = stoi(dig);

                st.push({temp, digit});
                i = j - 1;
            }
            else if (ch == '(') {
                st.push({"(", -1});
            }
            else if (ch == ')') {
                int j = i + 1;
                string dig = "";
                while (j < n && isdigit(formula[j])) {
                    dig += formula[j];
                    j++;
                }
                if (dig == "") dig = "1";
                int digit = stoi(dig);

                vector<pair<string, int>> v;
                while (!st.empty() && st.top().first != "(") {
                    pair<string, int> p = st.top();
                    st.pop();
                    v.push_back({p.first, p.second * digit});
                }
                st.pop();
                for (auto &p : v) {
                    st.push(p);
                }
                i = j - 1;
            }
        }
        map<string, int> mp;
        while (!st.empty()) {
            pair<string, int> p = st.top();
            st.pop();
            mp[p.first] += p.second;
        }
        string ans = "";
        for (auto &it : mp) {
            ans += it.first;
            if (it.second > 1) {
                ans += to_string(it.second);
            }
        }
        return ans;
    }
};