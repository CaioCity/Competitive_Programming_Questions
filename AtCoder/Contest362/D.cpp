// https://atcoder.jp/contests/abc362/tasks/abc362_d
// Shortest Path 3

#include <bits/stdc++.h>

#define int int64_t

typedef std::pair<int,int> pii;

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,M,U,V,C;
    std::cin>>N>>M;

    std::vector<int> ans(N+1,-1);

    // peso do vertice
    std::vector<int> cost (N+1); 
    for(int i=1; i<=N; ++i)
        std::cin>>cost[i];

    // guardar as arestas em L.A. - edges[start] = {target, edge_cost}
    std::vector<std::vector<pii>> edges(N+1, std::vector<pii>(0)); 

    for(int i=0; i<M; ++i){
        std::cin>>U>>V>>C;
        edges[U].push_back({V,C});
        edges[V].push_back({U,C});
    }

    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> heap;

    for(auto& [V,C] : edges[1])
        heap.push({C+cost[1],V});

    while(!heap.empty()){
        std::tie(C,V) = heap.top();
        heap.pop();

        if(ans[V]!=-1)
            continue;

        ans[V] = cost[V] + C;

        for(auto& [U,val] : edges[V])
            heap.push({ans[V]+val,U});
    }

    for(int i=2; i<=N; ++i)
        std::cout<<ans[i]<<' ';

    return 0;
}
