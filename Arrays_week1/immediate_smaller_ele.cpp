//Given an integer array Arr of size N. For each element in the array, check whether the right adjacent element (on the next immediate position) 
//of the array is smaller. If next element is smaller, update the current index to that element. If not, then  -1.

#include <bits/stdc++.h>

using namespace std;

class Solution{
public:	
	void immediateSmaller(int *arr, int n) {
	    for(int i=0; i<n; ++i)
	    {
	        if(arr[i+1]<arr[i])
	            arr[i] = arr[i+1];
	        else
	            arr[i] = -1;
	        if(i == n-1)
	        {
	            arr[i] = -1;
	            break;
	        }
	    }
	}

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}