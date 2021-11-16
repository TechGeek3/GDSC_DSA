//You are given an integer N. Print numbers from 1 to N without the help of loops.

#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:
    void printTillN(int N)
    {
        // Write Your Code here
        if(N == 0)
            return;
            
        printTillN(N-1);
        
        cout<<N<<" ";
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        ob.printTillN(N);
        cout<<endl;
    }
    return 0;
}
        