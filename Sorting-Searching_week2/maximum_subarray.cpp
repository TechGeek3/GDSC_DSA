//Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

//A subarray is a contiguous part of an array.

class Solution {
public:
    int maxSubArray(vector<int>& nums)                  //[-2, -1]
    {
        if(nums.size() == 1)
            return nums[0];
        
        int sum_final = nums[0];                          //Kadane's Alogrithm
        int sum_here = 0;
        
        for(int i = 0 ; i<nums.size() ; ++i)
        {
            sum_here = sum_here + nums[i];
            if(sum_here > sum_final)
                sum_final = sum_here;
            
            if(sum_here < 0)
                sum_here = 0;
        }
        return sum_final;
    }
};