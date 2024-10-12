class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& A) {
        int n = A.size();
        set<int> s(A.begin(), A.end());
        
        unordered_map<int, int> m; int rank = 1;
        
        for(auto &x: s) {
            m[x] = rank++;
        }
        
        for(int i=0; i<n; i++) {
            A[i] = m[A[i]];
        }
        return A;
    }
};