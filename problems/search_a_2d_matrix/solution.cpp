class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int x) {
        int m = matrix.size(), n = matrix[0].size(), l = 0, r = m-1, mid;
        
        while(l <= r){
            mid = l + (r-l)/2;
            
            if(matrix[mid][0]==x || matrix[mid][n-1]==x) return true;
            
            if(matrix[mid][0] < x && matrix[mid][n-1] > x) 
                return binarySearch(matrix, x, mid);
            
            if(matrix[mid][0] > x) r = mid-1;
            
            if(matrix[mid][n-1] < x) l = mid+1;
        }
        
        return 0;
    }
    
    bool binarySearch(vector<vector<int>> &matrix, int x, int row){
        int l=0, r=matrix[0].size()-1, mid;
        
        while(l <= r){
            mid = l + (r-l)/2;
            if(matrix[row][mid] == x) return true;
            else if(matrix[row][mid] > x) r = mid-1;
            else l = mid+1;
        }
        return false;
        
    }
};