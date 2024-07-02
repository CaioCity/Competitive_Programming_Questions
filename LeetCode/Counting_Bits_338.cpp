// https://leetcode.com/problems/counting-bits/
// 338 - Counting Bits

// Code O(n)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        int pot2 = 1, aux, count;
        ans[0]=0;

        for(int i=1; i<=n; ++i){
            if(i==pot2){
                pot2<<=1;
                ans[i]=1;
            }
            else{
                if(i&1){
                    ans[i]=ans[i-1]+1;
                    continue;
                }
                int j= i-1;
                for(aux=1, count=0; aux<j && (aux & j); aux<<=1)
                    ++count;
                ans[i]=ans[i-1]-count+1;
            }
        }
        return ans;
    }
};

