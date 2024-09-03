// https://leetcode.com/problems/sum-of-digits-of-string-after-convert
// 1945 - Sum of Digits of String After Convert

class Solution {
public:
    int getLucky(string S, int k) {
        int sum=0, aux;

        for(auto c : S){
            aux = (int)(c - 'a' )+1;
            sum+=(aux/10 + aux%10);
        }
        S = to_string(sum);

        while(--k){
            sum = 0;
            for(auto c : S){
            aux = (int)(c - '0' );
            sum+=(aux/10 + aux%10);
            }
            S = to_string(sum);
        }
        return sum;
    }
};
