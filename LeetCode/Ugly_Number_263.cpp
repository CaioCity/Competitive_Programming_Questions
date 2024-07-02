// https://leetcode.com/problems/ugly-number/description/
// 263 - Ugly Number

class Solution {
public:
    bool isUgly(int n) {
        if(n==0)
            return false;
        while(!(n&1))
            n>>=1;
        while(n%3==0)
            n/=3;
        while(n%5==0)
            n/=5;
        if(n==1)
            return true;
        else return false;
    }
};
