// https://leetcode.com/problems/coin-change/description/
// 322 - Coin Change

class Solution {
public:
    int DP(int target, vector<int>& coins, vector<int>& ans){
        if(ans[target] != -10)
            return ans[target];
        if(target<coins[0]) 
            return ans[target]=-1;
        
        int min = INT32_MAX;
        
        for(auto C : coins){
            if(target<C)
                break;
            int P = DP(target - C, coins, ans);
            if(P != -1)
                min=std::min(min, P+1);         
        }
        if(min==INT32_MAX)
            return ans[target]= -1;
        ans[target]=min;
        return ans[target];
    }

    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;

        vector<int> ans (amount+5,-10);

        int i,tam=coins.size();

        std::sort(coins.begin(),coins.end());

        for(i=0; i<tam && coins[i]<=amount; ++i)
            ans[coins[i]]=1;

        coins.erase(coins.begin()+i,coins.end());
        
        return DP(amount, coins, ans);
    }
};
