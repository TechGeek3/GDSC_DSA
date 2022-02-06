//Given N integers, the task is to insert those elements in the queue. Also, given M integers, task is to find the 
//frequency of each number in the Queue.

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void insert(queue<int> &q, int k){                               //// Function to insert element into the queue
            q.push(k);
    }

    int findFrequency(queue<int> &q, int k){                          //Function to find frequency of an element
        int count = 0;                                                //return the frequency of k
        queue<int> temp = q;
        while(temp.size())
        {
            if(temp.front() == k)
            {
                count++;
    
            }
            temp.pop();
        }
        return count;
    }
    
};

int main() {
    
		int testcase;
		cin>>testcase;
		
		while(testcase-- > 0){
		    queue<int> q;                                         // Declaring Queue
		    int n, k;
		    cin>>n;
		    
		    Solution obj;                                        // Invoking object of Geeks class
		    
		    for(int i = 0;i<n;i++){
		        cin >> k;
		        obj.insert(q, k);
		    }
		   
		    int m;
		    cin >> m;
		    for(int i = 0;i<m;i++){
		        cin >> k;
		        int f = obj.findFrequency(q, k);
		        if(f != 0){
		            cout<<f<<endl;
		        }
		        else{
		            cout<<"-1\n";
		        }
		    }
		}
	return 0;
}