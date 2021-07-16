class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> finalV;
        vector<int> v;
        int c;
        
        for(int i=1;i<=numRows;i++){
            c = 1;
            for(int j=1;j<=i;j++){
                v.push_back(c);
                c = c*(i - j)/j;
            }
            finalV.push_back(v);
            v.clear();
        }
        
        return finalV;
    }
};