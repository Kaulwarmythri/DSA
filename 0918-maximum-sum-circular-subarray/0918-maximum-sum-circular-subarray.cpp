class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int max_subarray_sum = INT_MIN, min_subarray_sum = INT_MAX, temp_min = 0, temp_max = 0, array_sum = 0;
        
        for(auto &x: nums) {
            array_sum += x;
            temp_max += x;
            max_subarray_sum = max(temp_max, max_subarray_sum);
            if(temp_max < 0) temp_max = 0;
            
            temp_min += x;
            min_subarray_sum = min(temp_min, min_subarray_sum);
            if(temp_min > 0) temp_min = 0;
        }
        
        if(min_subarray_sum == array_sum) return max_subarray_sum;
        
        return max(max_subarray_sum, array_sum - min_subarray_sum);
    }
};

//There can be 2 cases to get the maximum sum circular subarray.
// 1) [                 ]                                        2) [               ]     
//         -------                                                   ----      -----
//It can be a part of the array like this       or            It can be wrap-around like this
//Eg: [-1, 3, 2 -2]                                           Eg: [1, 5, -6, -3, 4, 2]
//         ----                                                    ----          ----
// We can use Kadane's algorithm to calculate the minimum_sbarray_sum (for case-2) and subtract it from total array's sum (array_sum). This will give the maximum wrap-around sum (or) the maximum sum circular subarray. 
//We'll return the max(maximum_subarray_sum, maximum_circular_subarray_sum) (Because in case 1, maximum_subarray_sum is larger).
//But, there might be a case where all elements are negative(Here, minimum_subarray_sum = array_sum). Then return  maximum_subarray_sum. (Do dry run for 3rd example to understand)
