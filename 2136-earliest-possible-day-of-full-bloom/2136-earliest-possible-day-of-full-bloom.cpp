class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
        int n = p.size(), bloomTime = 0;
        vector<pair<int, int>> v;
        
        for(int i=0; i<n; i++) 
            v.push_back({g[i], p[i]});
        
        sort(v.begin(), v.end(), greater<pair<int, int>>());   //sort a/c to grow times as its better to plant all the seeds that have larger growing time first as the other seeds might even grow before this grows completely (because of less growing time)
        
        int plantTime = 0;
        for(auto &x: v) {
            plantTime += x.second;
            bloomTime = max(bloomTime, plantTime + x.first + 1);   //+1 'cause bloom day is counted
        }
        return bloomTime - 1;   //as day 0 is included subtract 1
    }
};