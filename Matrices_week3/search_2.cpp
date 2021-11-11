//Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

//Integers in each row are sorted in ascending from left to right.
//Integers in each column are sorted in ascending from top to bottom.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int i=0 , j=n-1;
        
        while(i<m && j>=0)
        {
            if(target == matrix[i][j])
                return true;              
                
            else if(target > matrix[i][j])
                i++;
            else
                j--;
        }
        return false;
    }
};