// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/ 
// Append Characters to String to Make Subsequence

class Solution {
public:
    int appendCharacters(string s, string t) {
        int j=0;
        for(int i=0; i<s.length() && j<t.size(); i++)
            if(s[i]==t[j])
                j++;
        return (int)t.size() - j;
    }
};
