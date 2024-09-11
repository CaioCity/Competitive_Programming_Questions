// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/
// 1318 - Minimum Flips to Make a OR b Equal to c

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int aux,ans = 0;
        for(int i=0; i<31; ++i){
            aux = 1<<i;
            if((c & aux) == 0){
                if(b & aux)
                    ++ans;
                if(a & aux)
                    ++ans;
            } else if( ((a|b) & aux) == 0)
                    ++ans;
        }

        return ans;
    }
};
