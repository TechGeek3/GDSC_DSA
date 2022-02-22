//Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and 
//nums[i] + nums[j] + nums[k] == 0.

//Notice that the solution set must not contain duplicate triplets.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> vec;
        
        sort(nums.begin(), nums.end());
        
        if(nums.size() < 3)
            return vec;

        for(int i=0; i<nums.size()-2; i++)
        {
            if(i>0 && nums[i - 1] == nums[i])            //first ele or previous duplicates should be ignored
                continue;
            
            int j = i + 1, k = nums.size() - 1, sum = 0 - nums[i];
                
            while(j < k)                                      //two pointer approach - O(n2)
            {
                if(sum == nums[j] + nums[k])
                {
                    vec.push_back({nums[i], nums[j], nums[k]});
                       
                    k--;
                        
                    while(nums[k] == nums[k+1] && j<k)
                        k--;
                }
                    
                else if(sum > nums[j] + nums[k])
                    j++;
                   
                else
                    k--;
            }      
        }
        return vec;
    }
};