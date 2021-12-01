class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int ans=0, product=1, left=0;
        
        for(int right=0; right<nums.size(); right++){
            product *= nums[right];   //Multiply the product with the current number
            
            while(product>=k){
                product = product/nums[left]; /*If the product comes out to be >= k, slide the window and divide the product by nums[l] (Since, we only want product of a contiguous subarray)*/
                left++;
            }
            
            ans += right - left + 1; /*Each time add to ans the element itself(Each element is a subarray) and extra (right-left) subarrays. */
        }
        return ans;
        
    }
};