// https://leetcode.com/problems/greatest-common-divisor-of-strings/description
// Greatest Common Divisor of Strings

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1)
            return "";
        string ans;
        int aux=gcd(str1.size(),str2.size());
        for(int i=0; i<aux; ++i)
            ans+=str1[i];
        return ans;
    }
};
