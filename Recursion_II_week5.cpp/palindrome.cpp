//Given an integer, check whether it is a palindrome or not.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    string str = to_string(n);                                //convert int to string
		    
		    if(str.size() == 0)                                       //empty is also a palindrome
		        return "Yes";
		        
		    bool flag = auxFunc(str, 0, int(str.length()-1));
		    
		    if(flag)
		        return "Yes";
		        
		    return "No";
		}
	
		bool auxFunc(string n, int i, int j)
		{
		    if(i == j)                                                //single digit
		        return true;
		    
		    if(n[i] != n[j])
		        return false;
		        
		    if(i <= j)
		        return auxFunc(n, i+1, j-1);
		    
		    return true;
		}   
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}