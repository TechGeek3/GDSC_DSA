//Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        long long int sum = arr[0];
        int i = 0, j = 0;
        
        while(i < n && j < n)
        {
            if(sum == s)
                return {i + 1, j + 1};
            
            else if(sum < s)
            {
                j++;
                sum = sum + arr[j];
            }
            
            else
            {
                sum = sum - arr[i];
                i++;
            }
        }
        return {-1};
    }
};

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}