//Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//If target is not found in the array, return [-1, -1].
//You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> vec;
        if(nums.size()==0)
        {
            vec.push_back(-1);
            vec.push_back(-1);
            return vec;
        }
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]==target)
            {
                vec.push_back(i);
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;--i)
        {
            if(nums[i]==target)
            {
                vec.push_back(i);
                break;
            }
        }
        if(vec.empty())
        {
            vec.push_back(-1);
            vec.push_back(-1);
        }
        return vec;
    }
};