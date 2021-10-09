//Given an array of integers of size, N. Assume ‘0’ as the invalid number and all others as a valid number. Write a program that modifies the 
//array in such a way that if the next number is a valid number and is the same as the current number, double the current number value and 
//replace the next number with 0. After the modification, rearrange the array such that all 0’s are shifted to the end and the sequence of the 
//valid number or new doubled number is maintained as in the original array.

#include <bits/stdc++.h> 
using namespace std; 

class Solution{
    public:
        void modifyAndRearrangeArr(int arr[], int n) 
        { 
    	// Complete the function
    	    int non_zero = 0;
    	    
    	    for(int i=0 ; i<n ; ++i)
    	    {
    	        if(arr[i] == arr[i+1] && arr[i]!=0)
    	        {
    	            arr[i] = 2*arr[i];
    	            arr[i+1] = 0;
    	        }
    	        if(arr[i] == 0)
    	            continue;
    	        
    	        arr[non_zero++] = arr[i];
    	    }
        
            for(int j=non_zero ; j<n ; ++j)
    	    {
    	        arr[j] = 0;
    	    }
    	
    }
}; 

int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        ob.modifyAndRearrangeArr(arr, n);
        for(int i=0;i<n;i++)
            cout << arr[i] << " ";
        cout << endl;
        
    }

	return 0; 
}