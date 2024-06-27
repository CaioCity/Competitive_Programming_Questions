// https://leetcode.com/problems/is-subsequence/description
// Is Subsequence

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tamt=t.size(),tams=s.size(),i,j;
        for(i=0, j=0; j<tamt; ++j)
            if(s[i]==t[j]){
                ++i;
                if(i==tams)
                    break;
            }
        if(i==tams)
            return 1;
        return 0;
    }
};
