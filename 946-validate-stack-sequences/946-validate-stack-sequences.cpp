class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0, n = pushed.size();
        for(; i<n; i++){
            st.push(pushed[i]);
            
            while(j < n && !st.empty() && st.top() == popped[j]){
                st.pop(); 
                j++;
            }
        }
        return j == n;
    }
};