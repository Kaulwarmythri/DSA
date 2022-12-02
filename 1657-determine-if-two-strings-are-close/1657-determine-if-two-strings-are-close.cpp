class Solution {
public:
    bool closeStrings(string W1, string W2) {
        vector<int> A(26, 0), B(26, 0);
        set<char> S1, S2;
        
        for(auto &c: W1) 
            A[c - 'a']++, S1.insert(c);
        for(auto &c: W2) 
            B[c - 'a']++, S2.insert(c);
        
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        return A == B && S1 == S2;
    }
};