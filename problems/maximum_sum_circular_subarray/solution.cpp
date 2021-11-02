class Solution {
public:
    int maxkadane(vector<int>&nums)
    {
        int maxi = nums[0], sum = 0;
        for(auto i : nums)
        {
            sum+=i;
            if(sum > maxi)
                maxi = sum;
            if(sum < 0)
                sum = 0;
        }
        return maxi;
    }
    int minkadane(vector<int>&nums)
    {
        int maxi = nums[0], sum = 0;
        for(auto i : nums)
        {
            sum+=i;
            if(sum < maxi)
                maxi = sum;
            if(sum > 0)
                sum = 0;
        }
        return maxi;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int s = 0;
        s = accumulate(nums.begin(),nums.end(),s);
        int x = maxkadane(nums);
        int y = minkadane(nums);
        if(x < 0 and y < 0 and s < 0)
            if(s-y > x)
                return x;
        return max(x,s-y);
    }
};