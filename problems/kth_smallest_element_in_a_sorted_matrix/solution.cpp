class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), l = matrix[0][0], r = matrix[n- 1][n - 1];
        
        while(l<r){
            int mid = l + (r-l)/2;
            
            if(countSmaller(matrix, mid) < k) l = mid + 1;
            else r = mid;
        }
        return  r;
    }
    int countSmaller( vector<vector<int>>& matrix, int mid){
        int n = matrix.size(), row = 0, col = n - 1, ans = 0;
        
        while(row <= n-1 && col >= 0){
            if(matrix[row][col] <= mid){
                ans += col + 1;
                row++;
            }
            else col--;
        }
        return ans;
    }
};



