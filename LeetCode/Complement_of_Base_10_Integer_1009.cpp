// https://leetcode.com/problems/complement-of-base-10-integer/description/
// 1009 - Complement of Base 10 Integer

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
