class Solution {
    int n;
public:
    int kthSmallest(vector<vector<int>>& M, int k) {
        n = M.size();
        int l = M[0][0], r = M[n-1][n-1];
        
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(check(M, mid, k) < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    
    int check(vector<vector<int>> &M, int mid, int k) {
        int count = 0, row = 0, col = n-1;
        
        while(row < n && col >= 0) {
            if(M[row][col] <= mid) 
                count += col + 1,
                row++;
            else 
                col--;
        }
        return count;
    }
};