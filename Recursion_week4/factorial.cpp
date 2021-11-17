//Given a positive integer, N. Find the factorial of N.

#include<bits/stdc++.h> 
using namespace std;

class Solution{
public:
    long long int factorial(int N){
        //code here
        if(N == 0)
            return 1;
            
        return N * factorial(N-1);
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.factorial(N) << endl;
    }
    return 0; 
}