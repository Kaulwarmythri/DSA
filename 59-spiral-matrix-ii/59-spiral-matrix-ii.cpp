class Solution {
public:
    vector<vector<int>> generateMatrix(int p) {
        int i = 0, m = p-1;
        int j = 0, n = p-1;
        int val = 0;
		
        vector<vector<int>> v(p, vector<int> (p));
        
        while(i <= m && j <= n)
        {
            for(int k = j; k <= n; ++k)
                v[i][k] = ++val;
            i++;
				
            for(int l = i; l <= m; ++l)
                v[l][n] = ++val;
            n--;
				
            if(i <= m && j <= n) {
                for(int k = n; k >= j; --k)
                    v[m][k] = ++val;
                m--;
					
					// move up (col will be fixed)
                for(int l = m; l >= i; --l) 
                    v[l][j] = ++val;
                j++;
            }
        }
        return v;
    }
};

