//Write a function that reverses a string. The input string is given as an array of characters s.
//You must do this by modifying the input array in-place with O(1) extra memory.

class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        ref(s, 0, s.size()-1);
        
    }
    void ref(vector<char>& s, int i, int j)
    {
        if(i>=j)
            return;
        
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        
        ref(s, i+1, j-1);
    }
};