class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    double a = sqrt((pow(points[i][0] - points[j][0], 2)) + pow(points[i][1] - points[j][1], 2)), 
                    b = sqrt((pow(points[j][0] - points[k][0], 2)) + pow(points[j][1] - points[k][1], 2)), 
                    c = sqrt((pow(points[k][0] - points[i][0], 2)) + pow(points[k][1] - points[i][1], 2)), 
                    s = (a + b + c) / 2;
                    double area = sqrt(s * (s - a) * (s - b) * (s - c));
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};


//Area = √s(s-a)(s-b)(s-c)  => s = (a + b + c)/2;