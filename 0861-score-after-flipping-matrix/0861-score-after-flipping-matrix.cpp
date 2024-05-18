class Solution {
public:
    int matrixScore(vector<vector<int>>& G) {
        int m = G.size(), n = G[0].size();
        
        int score = m * (1 << (n-1));
        
        for(int j=1; j<n; j++) {
            int colCount = 0;
            
            for(int i=0; i<m; i++) {
                colCount += !G[i][0] ?  G[i][j] ^ 1 : G[i][j];
            }
            
            if(colCount < m - colCount)
                score += (m - colCount) * (1 << (n - 1 - j));
            else 
                score += colCount * (1 << (n - 1 - j));
        }
        
        return score;
    }
};

//Any cell's contribution to the score is -> 2 ^ (n-1-j) --> j = col, n = G[0].size()

//  1    1    1    1
// 2^3  2^2  2^1  2^0
//  8  > 4  + 2  + 1

//So the first bit in any row is of utmost priority. If the first bit is not 1, flip the entire row.


//Then check every column, if the column has more number of 1's than 0's, no need for a col flip. otherwise flip it (to increase it's contribution to the score)

//Add up all the contributions

// int matrixScore(vector<vector<int>>& G) {
//     int m = G.size(), n = G[0].size();

//     int score = 0;
//     for(int i=0; i<m; i++) {
//         if(!G[i][0])
//             for(int j=0; j<n; j++)
//                 G[i][j] ^= 1;
//     }

//     for(int j=1; j<n; j++) {
//         int colCount = 0; //number of 1s in the column
//         for(int i=0; i<m; i++)
//             colCount += G[i][j];

//         if(colCount < n - colCount)
//             for(int i=0; i<m; i++)
//                 G[i][j] ^= 1;
//     }

//     for(int i=0; i<m; i++) {
//         for(int j=0; j<n; j++) {
//             score += G[i][j] * (1 << (n - 1 - j));
//         }
//     }
//     return score;
// }