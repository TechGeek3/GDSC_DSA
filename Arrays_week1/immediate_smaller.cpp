//Given an array arr[] of size N containing positive integers and an integer X, find the element in the array which is smaller than X
//and closest to it.

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int immediateSmaller(int arr[], int n, int x)
    {
        int min=0;
        for(int i=0;i<n;++i)
        {
            if(x-min>x-arr[i] && x-arr[i]>0)
                min=arr[i];
        }
        if(min>0)
            return min;
        else
            return -1;
    }
};

int main()
{	
	int t;
	cin>>t;
	
	while(t--)
	{	    
        int n;
        cin >> n;
    	
    	int arr[n];

    	for(int i=0 ; i<n; i++)
        {        	    
            cin >> arr[i];
    	}   	
        int x;
    	cin >> x;
    	Solution ob;
    	cout << ob.immediateSmaller(arr, n, x) << endl;
	}	
	return 0;
}