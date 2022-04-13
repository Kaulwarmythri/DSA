class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> v;
        int m = matrix.size()-1, n = matrix[0].size()-1;
        int i = 0, j = 0;
        
        while(i <= m && j <= n) {
            for(int k=j; k<=n; k++) v.push_back(matrix[i][k]);
            i++;
            
            for(int l=i; l<=m; l++) v.push_back(matrix[l][n]);
            n--;
        
            if(i <= m) {
                for(int k=n; k>=j; k--) v.push_back(matrix[m][k]);
                m--;
            }
        
            if(j <= n) {
                for(int l=m; l>=i; l--) v.push_back(matrix[l][j]);
                j++;
            }
        }
        
        return v;
    }
};


//  while (k < m && l < n) {
//         /* Print the first row from
//                the remaining rows */
//         for (i = l; i < n; ++i) {
//             cout << a[k][i] << " ";
//         }
//         k++;
 
//         /* Print the last column
//          from the remaining columns */
//         for (i = k; i < m; ++i) {
//             cout << a[i][n - 1] << " ";
//         }
//         n--;
 
//         /* Print the last row from
//                 the remaining rows */
//         if (k < m) {
//             for (i = n - 1; i >= l; --i) {
//                 cout << a[m - 1][i] << " ";
//             }
//             m--;
//         }
 
//         /* Print the first column from
//                    the remaining columns */
//         if (l < n) {
//             for (i = m - 1; i >= k; --i) {
//                 cout << a[i][l] << " ";
//             }
//             l++;
//         }
//     }