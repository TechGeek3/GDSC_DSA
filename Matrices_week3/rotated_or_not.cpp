//Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree 
//increments, or false otherwise.

 

class Solution {
public:
    void swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) 
    {
        for(int i=0 ; i<4 ; ++i)                           //max possible rotations are four
        {
        int n = mat.size();
            
        for(int i=0 ; i<n ;++i)                            //transpose of matrix
        {
            for(int j=0 ; j<n ; ++j)    
            {    
                if(i<j)
                {
                    swap(&mat[i][j], &mat[j][i]);
                }
            }
        }
        for(int i=0 ; i<n ; ++i)                           //reverse matrix row wise
        {
        int start=0, end=n-1;
            
        while(start<end)
        {
            swap(&mat[i][start], &mat[i][end]);
            start++;
            end--;
        }
        }
       if(mat == target)                                  //compare with the target
           return true;
        }
        return false;
    }
};