// https://leetcode.com/problems/palindromic-substrings/description/
// 647 - Palindromic Substrings

class Solution {
public:
    int countSubstrings(string s) {
        int ans=0,tam=s.size();
        for(int index=0; index<tam; ++index){
            for(int i=index-1, j=index+1; i>=0 && j<tam && s[i]==s[j]; --i, ++j)
                ++ans;
            for(int i=index, j=index+1; i>=0 && j<tam && s[i]==s[j]; --i, ++j )
                ++ans;
        }
        ans+=tam;
        return ans;
    }
};
