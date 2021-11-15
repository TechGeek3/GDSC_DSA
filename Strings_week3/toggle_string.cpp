//You have been given a String S consisting of uppercase and lowercase English alphabets. You need to change the case of each alphabet in this
//String. That is, all the uppercase letters should be converted to lowercase and all the lowercase letters should be converted to uppercase. 
//You need to then print the resultant String to output.

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    
    cin>>str;
    for(int i=0 ; i<str.length() ; ++i)
    {
        if(str.length() == 0)
            return 0;
        if(str[i]>=65 && str[i]<=90)
            str[i] = str[i] + 32;

        else
            str[i] = str[i] - 32;  
        
    }
    cout<<str;
    return 0;
}