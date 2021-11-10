//Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        bool ans = false;
        
        for(int i=0 ; i<m-1 ; ++i)
        {
            if(target >= matrix[i][0] && target < matrix[i+1][0])
            {
                for(int j=0 ; j<n ; ++j)
                {
                    if(target == matrix[i][j])
                        ans = true;
                }
            }
            else
            {
                for(int j=0 ; j<n ; ++j)
                {
                    if(target == matrix[m-1][j])
                        ans = true;
                }
            }
        }
        if(m==1)
        {
            for(int j=0 ; j<n ; ++j)
            {
             if( target == matrix[0][j])
                ans = true;   
            }
        }
        return ans;
    }
};

//Another Approach
/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        if(target < matrix[0][0])
            return false;

        else
        {
            int i=0 , j=n-1;
            while(i>=0 && j>=0 && i<m && j<n)
            {
            if(target == matrix[i][j])
                return true;
            
            else if(target > matrix[i][j])
                i++;

            else
                j--;
            }   
        }
        return false;
    }
};