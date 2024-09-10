// https://atcoder.jp/contests/abc350/tasks/abc350_d
// D - New Friends

#include <bits/stdc++.h>

#define int int64_t
#define DEBUG(x) std::cout<<#x<<" = "<<x<<'\n';
const int INF = 1ll<<55;

// Retorna a quantidade de arestas do K-N (grafo completo de N vertices)
int K(int N){
    return (N*(N-1))>>1;
}

int32_t main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0);

    int N,M,U,V,ans=0;
    std::cin>>N>>M;

    std::vector<std::vector<int>> edges(N+1,std::vector<int> (0));
    std::vector<int> visited(N+1,0);
    std::vector<std::pair<int,int>> conex; // guarda o tamanho das componentes conexas e quantas arestas elas ja possuem;

    for(int i=0; i<M; ++i){
        std::cin>>U>>V;
        edges[U].push_back(V);
        edges[V].push_back(U);
    }

    for(int i=1; i<=N; ++i)
        if(!visited[i]){
            int tam = 0,used=0;
            std::queue<int> fila;
            fila.push(i);
            while(!fila.empty()){
                U = fila.front();
                fila.pop();
                if(visited[U])
                    continue;
                visited[U]=1;
                ++tam;
                for(int V : edges[U])
                    if(!visited[V]){
                        ++used;
                        fila.push(V);
                    }
            }
            conex.push_back({tam,used});
        }

    for(auto& [tam,used] : conex)
        ans+= (K(tam) - used);
        
    std::cout<<ans<<'\n';

    return 0;
}
