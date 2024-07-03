// https://neps.academy/br/exercise/28
// Frete

#include <bits/stdc++.h>

#define int int64_t

int32_t main() {

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,M,U,V,C;
    std::cin>>N>>M; 

    std::vector<std::vector<std::pair<int,int>>> edges (N+1, std::vector<std::pair<int,int>> (0)) ;

    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>> > heap;

    for(int i=0; i<M; ++i){
        std::cin>>U>>V>>C;
        edges[U].push_back({V,C});
        edges[V].push_back({U,C});
    }

    int* visited = (int*)calloc(N+1,sizeof(int));

    for(auto [T,cost] : edges[1])
        heap.push({cost,T});

    while(!heap.empty()){
        std::tie(C,V)=heap.top();
        heap.pop();

        if(V==N){
            std::cout<<C<<"\n";
            break;
        }

        if(visited[V])
            continue;

        visited[V]=1;

        for(auto [Next,Valor] : edges[V])
            heap.push({C+Valor,Next});
    }
    
    return 0;
}
