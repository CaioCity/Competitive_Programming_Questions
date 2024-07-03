// https://neps.academy/br/exercise/28
// Frete

#include <bits/stdc++.h>

#define int int64_t

typedef std::tuple<int,int,int> trio;

int32_t main() {

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,M,A,B,C;
    std::cin>>N>>M; 

    std::vector<std::vector<std::pair<int,int>>> edges (N+1, std::vector<std::pair<int,int>> (0)) ;

    std::priority_queue<trio, std::vector<trio>, std::greater<trio> > heap;

    for(int i=0; i<M; ++i){
        std::cin>>A>>B>>C;
        edges[A].push_back({B,C});
        edges[B].push_back({A,C});
    }

    std::vector<int> cost (N+1, INT32_MAX);

    for(auto [T,V] : edges[1])
        heap.push({V,1,T});

    int ans=INT32_MAX;

    while(!heap.empty()){
        std::tie(C,A,B)=heap.top();
        heap.pop();

        if(B==N){
            ans=std::min(ans,C);
            continue;
        }

        if(cost[B]<=C || C>ans)
            continue;

        cost[B]=C;

        for(auto [Next,Valor] : edges[B])
            heap.push({C+Valor,B,Next});
    }

    std::cout<<ans<<"\n";
    
    return 0;
}
