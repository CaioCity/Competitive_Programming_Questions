// https://cses.fi/problemset/task/1679/
// CSES - Course Schedule
// Topological Sort

#include <bits/stdc++.h>

#define int int64_t
#define DEBUG(x) std::cout<<#x<<" = "<<x<<'\n';
const int INF = 1ll<<55;
// int mx[4] = {1,0,-1,0}, my[4] = {0,1,0,-1};

int32_t main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0);
    
    int N,M,U,V;
    std::cin>>N>>M;

    std::vector<std::vector<int>> D_graph (N);
    std::vector<int> order;
    std::vector<int> in_degree(N,0);
    std::queue<int> Q;

    for(int i=0; i<M; ++i){
        std::cin>>U>>V;
        --U; --V;
        ++in_degree[V];
        D_graph[U].push_back(V);
    }

    for(int i=0; i<N; ++i)
        if(in_degree[i]==0)
            Q.push(i);

    while(!Q.empty()){
        U = Q.front();
        Q.pop();
        order.push_back(U);
        
        for(int V : D_graph[U])
            if(--in_degree[V]==0)
                Q.push(V);
    }

    if(order.size()==N){
        for(int i=0; i<N; ++i)
            std::cout<<order[i]+1<<' ';
        std::cout<<'\n';
    }
    else std::cout<<"IMPOSSIBLE\n";

    return 0;
}
