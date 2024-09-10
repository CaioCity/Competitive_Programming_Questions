// https://leetcode.com/problems/find-eventual-safe-states/description/
// 802 - Find Eventual Safe States

class Solution {
public:
    const int INDETERMINED = -1, UNSAFE = 0, SAFE = 1, CYCLING = 2;
    bool status(int node, vector<vector<int>>& graph, vector<int>& DP){
        if(DP[node] == CYCLING) return DP[node] = UNSAFE;
        if(DP[node] != INDETERMINED) return DP[node];
        DP[node] = CYCLING;
        for(int target : graph[node])
            if(status(target,graph,DP) == UNSAFE || status(target,graph,DP) == CYCLING)
                return DP[node] = UNSAFE;
        return DP[node] = SAFE;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> DP(N,INDETERMINED);
        vector<int> ans;
        for(int i=0; i<N; ++i)
            if(status(i,graph,DP) == SAFE)
                ans.push_back(i);
        return ans;
    }
};
