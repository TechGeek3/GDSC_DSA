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