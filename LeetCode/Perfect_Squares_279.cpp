// https://leetcode.com/problems/perfect-squares/description
// 279 - Perfect Squares

class Solution {
public:
    int min_coins(int i, vector<int>& coins, vector<int>& ans){
        if(ans[i]!=-1)
            return ans[i];
        ans[i]=INT32_MAX;
        for(auto C : coins){
            if(C>i)
                break;
            ans[i]=min(min_coins(i-C, coins, ans)+1, ans[i]);
        }
        ans[i]=min(ans[i],i);
        return ans[i];
    }

    int numSquares(int n) {
        vector<int> coins, ans(n+1,-1);
        int i;
        for(i=1; i*i<n; ++i)
            coins.push_back(i*i);
        if(i*i==n)
            return 1;
        return min_coins(n,coins,ans);
    }
};
