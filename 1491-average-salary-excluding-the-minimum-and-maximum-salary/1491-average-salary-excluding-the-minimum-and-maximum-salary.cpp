class Solution {
public:
    double average(vector<int>& A) {
        sort(A.begin(), A.end());
        
        return (accumulate(A.begin(), A.end(), 0.) - A[0] - A[A.size()-1]) / (A.size() - 2);
    }
};