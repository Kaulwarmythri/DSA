class Solution {
public:
    int jump(vector<int>& nums) {
        int left=0, right=0, steps=0;
        while(right < nums.size()-1){
            int max_position=left;
            
            for(int i=left;i<=right;i++){
                max_position = max(max_position, nums[i]+i);   
            }
            steps++;
            left=right+1;
            right=max_position;   
        }
        return steps;
        
    }
};