//Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than 
//or equal to all the elements to its right side. The rightmost element is always a leader. 

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> leaders(int a[], int n)
    {
        /*vector<int> vec;                             //Unoptimised Solution
        for(int i=0;i<n-1;++i)
        {
            int count=0;
            for(int j=i+1;j<n;++j)
            {
                if(a[i]>=a[j])
                    count++;
            }
            if(count==n-i-1)
                vec.push_back(a[i]);
        }
        vec.push_back(a[n-1]);
        return vec;*/

        vector<int> vec;
        int l=a[n-1];
        vec.push_back(l);
        for(int i=n-2;i>=0;--i)
        {
            if(a[i]>=l)
            {
                vec.push_back(a[i]);
                l=a[i];
            }    
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};

int main()
{
   long long t;
   cin >> t;                                                //testcases
   while (t--)
   {
        long long n;
        cin >> n;
        
        int a[n];
        
        for(long long i =0;i<n;i++)                           //inserting elements in the array
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> v = obj.leaders(a, n);                   //calling leaders() function
        
        for(auto it = v.begin();it!=v.end();it++)            //printing elements of the vector
        {
            cout << *it << " ";
        }
        cout << endl;
   }
}
