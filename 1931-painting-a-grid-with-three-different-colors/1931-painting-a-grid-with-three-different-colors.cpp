class Solution {
    int dp[1000][1024] = {}, mod = 1e9 + 7;
public:
    int colorTheGrid(int m, int n, int i = 0, int j = 0, int curr = 0, int prev = 0) {
        if(i == m) 
            return colorTheGrid(m, n, 0, j+1, 0, curr);
        if(j == n)
            return 1;
        
        if(!i && dp[j][prev])
            return dp[j][prev];
        
        int ans = 0;
        int up = i == 0 ? 0 : (curr >> (i-1) * 2) & 3, left = (prev >> i * 2) & 3;
        
        for(int c=1; c<=3; c++) {
            if(c != up && c != left) {
                ans = (ans + colorTheGrid(m, n, i+1, j, curr + (c << (i * 2)), prev)) % mod;
            }
        }
        
        if(i == 0) 
            dp[j][prev] = ans;
        return ans;
        
    }
};


//Since there are only max 5 rows ==> We can use a mask to store the colors of cells (of each row) that belong to one particular column  (Mask can be max ==> 11 11 11 11 11 (imagine these as colors (1 -> 01, 2 -> 10, 3 -> 11) vertically) ==> 1023).

//For each cell try all colors and check to see if it matches with up or left cells' colors.

//curr -> stores the mask of current cell
//prev -> stores the mask of prev cell

//dp[col][maskofprevcol] -> stores the no. ways to color all cols from col to n with the prev col's mask being "maskofprevcol".