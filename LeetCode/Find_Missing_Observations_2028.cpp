// https://leetcode.com/problems/find-missing-observations
// 2028 - Find Missing Observations

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int N) {
        int M = rolls.size(), sum = 0, diff;

        for(int i=0; i<M; ++i)
            sum+=rolls[i];
        diff = mean*(N+M) - sum;

        if(diff<N || diff>N*6)
            return vector<int> (0);

        vector<int> ans (N,1);
        diff -= N;

        int index = 0;
        while(diff>0){
            ans[index]+=min(5,diff);
            ++index;
            diff-=5;
        }

        return ans;
    }
};
