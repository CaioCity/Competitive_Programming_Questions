// https://leetcode.com/problems/path-with-maximum-probability/description
// 1514 - Path with Maximum Probability

class Solution {
public:
    double maxProbability(int N, vector<vector<int>>& Edges, vector<double>& succProb, int start, int end) {
        int U,V;
        double cost = 0, ans = 0;
        vector<vector<pair<int,double>>> edges (N);

        for(int i=0, tam = Edges.size(); i<tam; ++i){
            U = Edges[i][0]; V = Edges[i][1];
            edges[U].push_back({V,succProb[i]});
            edges[V].push_back({U,succProb[i]});
        }

        priority_queue<pair<double,int>> heap;
        vector<double> prob(N+4,0);

        for(auto [dest,cost] : edges[start])
            heap.push({cost,dest});
        
        while(!heap.empty()){
            tie(cost,U) = heap.top();
            heap.pop();

            if(cost<=prob[U])
                continue;

            if(U == end){
                if(cost>=heap.top().first)
                    return max(ans,cost);
                ans = max(ans,cost);
                continue;
            }

            prob[U] = cost;
            
            for(auto [V,C] : edges[U])
                if(C*cost>prob[V])
                    heap.push({C*cost,V});
        }

        return 0;
    }
};
