class Solution {
    
    int di[4] = {1, -1, 0, 0}, dj[4] = {0, 0, 1, -1};
    
     bool isPossible(vector<vector<int>> &mat , vector<vector<bool>> &visited , int mid , int i , int j) {
            if(i==mat.size()-1 && j==mat[0].size()-1) return true;
            
            visited[i][j]=true;
            for(int k=0;k<4;k++) {
                int newi=i+di[k];
                    int newj=j+dj[k];
                    
                    if(newi>=0 && newi<mat.size() && newj>=0 && newj<mat[0].size() && visited[newi][newj]==false) {
                            if(abs(mat[i][j]-mat[newi][newj])<=mid) {
                                  if(isPossible(mat ,visited,mid , newi , newj)==true)
                                      return true;
                            }   
                    }
            }
            return false;       
    }
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        int l=0,h=10000002;
        
        while(l<h) {
                int mid=(l + (h-l)/2);
                vector<vector<bool>> visited(m , vector<bool> (n , false));
                if(isPossible(heights , visited , mid , 0 , 0)==true)  h=mid;
                
                else l = mid+1;
        }
        return l;
    }
};