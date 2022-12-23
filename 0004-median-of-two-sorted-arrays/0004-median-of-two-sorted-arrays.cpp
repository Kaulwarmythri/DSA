class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m = A.size(), n = B.size();
        
        if(m > n) return findMedianSortedArrays(B, A);
        
        int low = 0, high = m;
        
        while(low <= high) {
            int cut1 = (low + high) / 2, cut2 = (m + n + 1) / 2 - cut1;
            
            int l1 = cut1 == 0 ? INT_MIN : A[cut1 - 1], l2 = cut2 == 0 ? INT_MIN : B[cut2 - 1];
            int r1 = cut1 == m ? INT_MAX : A[cut1], r2 = cut2 == n ? INT_MAX : B[cut2];
            
            if(l1 <= r2 && l2 <= r1) {
                if((m + n) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else 
                    return max(l1, l2);
            } else if(l1 > r2) {
                high = cut1 - 1;
            } else
                low = cut1 + 1;
        }
        return 0.0;
    }
};