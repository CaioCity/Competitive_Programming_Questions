// https://leetcode.com/problems/number-complement/
// 476 - Number Complement

class Solution {
public:
    int bitwiseComplement(int num) {
        int sum=0;
        if(num==0)  return 1;
        for(int64_t a=1,i=0; a<=num; ++i, a<<=1 )
            if(!(num&a))
                sum+=a;
        return sum;
    }
};
