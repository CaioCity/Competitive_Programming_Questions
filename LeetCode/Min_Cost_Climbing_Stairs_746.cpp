// https://leetcode.com/problems/min-cost-climbing-stairs/description/
// 746 - Min Cost Climbing Stairs

class Solution {
public:
    int top_down(int i, vector<int>& cost, vector<int>& past) {
        if(past[i]!=-1)
            return past[i];
        return past[i]=std::min( cost[i-1] + top_down(i-1, cost, past), cost[i-2] + top_down(i-2, cost, past) );
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> past (cost.size()+3,-1);
        past[0]=past[1]=0;
        return top_down(cost.size(), cost, past);        
    }
};
