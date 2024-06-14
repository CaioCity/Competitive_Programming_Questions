// https://neps.academy/br/exercise/297
// Caminho das Pontes- Dijkstra

#include <bits/stdc++.h>

typedef std::pair<int,int> pii;

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,M,S,T,B;
    int C,U,V;

    std::cin>>N>>M;

    std::vector<std::vector<pii>> bridges (N+2); // formato de lista de adj
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> fila;
    bool* visited = (bool*)calloc(N+2, sizeof(bool));

    for(int i=0; i<M; i++){
        std::cin>>S>>T>>B;
        bridges[S].push_back({T,B});
        bridges[T].push_back({S,B});
    }

    for(auto P : bridges[0])
        fila.push({P.second, P.first}); // custo , destino
    
    while( !fila.empty() ){
       
        C=std::get<0>(fila.top());
        V=std::get<1>(fila.top());

        if(V==(N+1)){
            std::cout<<C<<'\n';
            return 0;
        }

        fila.pop();

        if(visited[V])
            continue;

        visited[V]=1;
        
        for( auto P : bridges[V] )
            fila.push({P.second + C, P.first});
        
    }

    return 0;
}
