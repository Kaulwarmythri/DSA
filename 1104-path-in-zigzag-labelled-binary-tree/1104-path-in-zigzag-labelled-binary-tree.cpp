class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int height = log2(label);
        vector<int> ans; ans.push_back(label);
        
        while(height) {
            int dis = (label - pow(2, height)) / 2;
            label = pow(2, height) - 1 - dis;
            ans.push_back(label);
            
            height--;
        }
        
        return vector<int>(ans.rbegin(), ans.rend());
    }
};