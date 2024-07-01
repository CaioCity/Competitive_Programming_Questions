// https://neps.academy/br/exercise/24
// Castelos da Nlogônia

#include <bits/stdc++.h>

void colorir(int C, int color[], std::vector<int>& V);

int32_t main() {

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,M;
    std::cin>>N>>M;

    int A,B,C;
    int* color=(int*)calloc(N+2,sizeof(int));
    std::vector<std::vector<int>> edge (N+1);

    for(int i=1; i<N; ++i){
        std::cin>>A>>B;
        edge[A].push_back(B);
        edge[B].push_back(A);
    }

    for(int i=0; i<M; ++i){
        std::cin>>A>>B>>C;

        color[A]=C;
        
        if(A==B)
            continue;
        
        std::queue<std::pair<int,std::vector<int>>> fila;
        for(int j=edge[A].size()-1; j>=0; --j)
            fila.push({edge[A][j],std::vector<int>(1,edge[A][j])});

        bool* visited=(bool*)calloc(N+1, sizeof(bool));
        visited[A]=1;

        while(!fila.empty()){
            int F = fila.front().first;
            if(visited[F]){
                fila.pop();
                continue;
            }
            visited[F]=1;
            if(F==B){
                colorir(C, color, fila.front().second);
                free(visited);
                break;
            }
            for(int k=edge[F].size()-1; k>=0; --k){
                fila.front().second.push_back(edge[F][k]);
                fila.push({edge[F][k],fila.front().second});
                fila.front().second.pop_back();
            }
            fila.pop();
        }
    }
    
    for(int i=1; i<N; ++i)
        std::cout<<color[i]<<' ';
    std::cout<<color[N]<<'\n';

    return 0;
}

void colorir(int C, int color[], std::vector<int>& V){
    for(auto i : V)
        color[i]=C;
}
