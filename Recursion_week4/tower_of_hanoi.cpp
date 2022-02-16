//The tower of Hanoi is a famous puzzle where we have three rods and N disks. The objective of the puzzle is to move the entire stack to 
//another rod. You are given the number of discs N. Initially, these discs are in the rod 1. You need to print all the steps of discs 
//movement so that all the discs reach the 3rd rod. Also, you need to find the total moves.

//Note: The discs are arranged such that the top disc is numbered 1 and the bottom-most disc is numbered N. Also, all the discs have 
//different sizes and a bigger disc cannot be put on the top of a smaller disc. Refer the provided link to get a better clarity about 
//the puzzle.

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:

    int count = 0;
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        if(N == 0)
            return count;
        
        toh(N-1, from, aux, to);
        count++;
        
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        toh(N-1, aux, to, from);
        
        return count;
    }
};

int main() {

    int T;
    cin >> T;                                                //testcases
    while (T--) {
        
        int N;
        cin >> N;                                            //taking input N
        
        Solution ob;                                         //calling toh() function
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}