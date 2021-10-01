//Given an array of integers nums, calculate the pivot index of this array.
//The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers 
//strictly to the index's right.
//If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the 
//right edge of the array.
//Return the leftmost pivot index. If no such index exists, return -1.

class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int sum_left=0,sum_right=0,total_sum=0;
        for(int i=0;i<nums.size();++i)
        {
            total_sum=total_sum+nums[i];
        }
        for(int i=0;i<nums.size();++i)
        {
            sum_right=total_sum-(sum_left+nums[i]);
            
            if(sum_left==sum_right)
                return i;
            
            sum_left=sum_left+nums[i];
        }
        return -1;
    }
};