// https://leetcode.com/problems/reverse-string/description/
// Reverse String

class Solution {
public:
    void reverseString(vector<char>& s) {
        int tam=s.size();
        int loop= tam/2;
        for(int i=0; i<loop; i++)
            swap(s[i],s[tam-1-i]);
        
    }
};
