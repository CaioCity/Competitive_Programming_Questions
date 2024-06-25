// https://leetcode.com/problems/merge-strings-alternately/
// Merge Strings Alternately

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i;
        for( i=0; i<word1.size() && i<word2.size(); i++){
            ans+=word1[i];
            ans+=word2[i];
        }
        if(i==word1.size())
            for(; i<word2.size();i++)
                ans+=word2[i];
        else
            for(; i<word1.size();i++)
                ans+=word1[i];

        return ans;
    }
};
