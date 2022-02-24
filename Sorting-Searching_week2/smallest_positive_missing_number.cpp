//You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.


//Approach 1 
/*#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)             
    { 
        sort(arr, arr + n);
        
        int start = 1;
        
        for (int i = 0; i < n; ++i)
        {
            if(arr[i] == start)
                start++;
        }
        
        return start;
    } 
};

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
}*/

//Approach 2
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    int segregate(int arr[], int n)              //move neg to left and pos to right
    {
        int j = 0;
        for(int i = 0; i < n; ++i)
        {
            if(arr[i] <= 0)
            {
                swap(&arr[i], &arr[j]);
                j++;
            }
        }
        return j;
    }
    
    int missing(int arr[], int n)
    {
        for(int i = 0; i < n; ++i)
        {
            if(arr[abs(arr[i]) - 1] > 0 && abs(arr[i]) - 1 < n)
               arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
        
        for(int i = 0; i < n; ++i)
        {
            if(arr[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
    
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        int shift = segregate(arr, n);
        return missing(arr + shift, n - shift);
    } 
};

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
}