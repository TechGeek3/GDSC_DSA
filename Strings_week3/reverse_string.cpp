//Write a function that reverses a string. The input string is given as an array of characters s.

class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int start = 0;
        int end = s.size()-1;
        
        while(start<end)
        {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};