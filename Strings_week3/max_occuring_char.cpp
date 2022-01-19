//Given a string str. The task is to find the maximum occurring character in the string str. If more than one character occurs the 
//maximum number of time then print the lexicographically smaller character.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int arr[26] = {0};
        int idx = 0;
        for(int i=0; i<str.length(); ++i)            //initialising the array with count of ele
        {
            char ch = str[i];
            
            if(ch>='a' && ch<='z')                   //idx will be acc to the ascii values - 'A/a'
                idx = ch - 'a';
                
            else if(ch>='A' && ch<='Z')
                idx = ch - 'A';
            
            arr[idx]++;
        }
        int max = arr[0];
        int pos = 0;
        for(int i=1; i<26; ++i) 
        {
            if(arr[i]>max)                           
            {
                max = arr[i];                          //max count found
                pos = i;                               //idx is required for returning char
            }
        }
        return char(pos+'a');                          //char is returned
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}