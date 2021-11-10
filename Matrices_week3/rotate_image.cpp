//You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
//You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. 
//DO NOT allocate another 2D matrix and do the rotation.

//Unoptimised Approach
/*class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for(int i=0 ; i<n; ++i)
        {
            for(int j=0 ; j<n ; ++j)
            {
                if(i<j)
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }
        for(int i=0; i<n ;++i)
        {
            int start=0,end=n-1;
            while(start<end)
            {
                int temp = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = temp;
                start++;
                end--;
            }
        }
        
    }
};*/

//Optimised Approach
class Solution {
public:
    void swap(int* a, int* b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        for(int i=0 ; i<n; ++i)
        {
            for(int j=0 ; j<n ; ++j)
            {
                if(i<j)
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
        }
        for(int i=0; i<n; i++) 
        {
        int start = 0;
        int end = n - 1;
 
        while (start < end) 
        {
            swap(&matrix[i][start], &matrix[i][end]);
            start++;
            end--;
        }
        }
    }
};

