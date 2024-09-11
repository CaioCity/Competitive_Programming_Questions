// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description
// 2220 - Minimum Bit Flips to Convert Number

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        for(int i=0; i<=30; ++i)
            if((start & 1<<i) ^ (goal & 1<<i))
                ++ans;
        return ans;
    }
};
