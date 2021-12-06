class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size(), step=0, ball=0;
        vector<int> ans(n, 0);
        
        for(int i=n-1;i>=0;i--){
            ans[i] = step;
            ball = boxes[i]=='1' ? ball+1 : ball;
            step += ball;
        }
        step=0, ball=0;
        for(int i=0;i<n;i++){
            ans[i] += step;
            ball = boxes[i]=='1' ? ball+1 : ball;
            step += ball;
        }
        
        return ans;
    }
};