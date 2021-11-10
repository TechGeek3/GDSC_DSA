//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        int T = 0 , B = n - 1 , L = 0 , R = n - 1, k = 1, dir = 0;
        vector<vector<int>> matrix(n, vector<int>(n,0));
        while(T <= B && L <= R)
        {
            if(dir==0)
            {
                for(int i=L ; i<=R ; ++i)
                {
                    matrix[T][i] = k;
                    k++;
                }
                T++;
            }
            if(dir==1)
            {
                for(int i=T ; i<=B ; ++i)
                {
                    matrix[i][R] = k;
                    k++;
                }
                R--;
            }
            if(dir==2)
            {
                for(int i=R ; i>=L ; --i)
                {
                    matrix[B][i] = k;
                    k++;
                }
                B--;
            }
            if(dir==3)
            {
                for(int i=B ; i>=T ; --i)
                {
                    matrix[i][L] = k;
                    k++;
                }
                L++;
            }
            dir = (dir+1)%4;
            if(k>n*n)
                break;
        }
        return matrix;
    }
};