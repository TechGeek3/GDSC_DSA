//Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int c0=0,c1=0,c2=0;
        for(int i=0;i<n;++i)
        {
            if(a[i]==0)
                c0++;
            else if(a[i]==1)
                c1++;
            else 
                c2++;
        }
        int i=0;
        while(c0)
        {
            a[i] = 0;
            c0--;
            i++;
        }
        while(c1)
        {
            a[i] = 1;
            c1--;
            i++;
        }
        while(c2)
        {
            a[i] = 2;
            c2--;
            i++;
        }
    }
    
};

int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}