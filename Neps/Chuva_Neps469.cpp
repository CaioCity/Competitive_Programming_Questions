// https://neps.academy/br/exercise/469
// Chuva (OBI 2019)

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    short int N,M;
    std::cin>>N>>M;

    char grid[N][M];

    for(short int i=0; i<N; i++)
        for(short int j=0; j<M; j++)
            std::cin>>grid[i][j];
    
    std::queue<std::pair<short int, short int>> fila;

    for(short int i=0; i<M; i++)
        if(grid[0][i]=='o'){
            fila.push({0,i});
            grid[0][i]='.';
        }

    short int i,j;
    while(!fila.empty()){
        std::tie(i,j)=fila.front();
        fila.pop();
        if(grid[i][j]=='o' || grid[i][j]=='#')
            continue;
        
        grid[i][j]='o';
        if((i+1)<N){
            if (grid[i+1][j]=='.'){
                grid[i+1][j]='o';
                fila.push({i+2,j});
            }
            else if(grid[i+1][j]=='#'){
                if(j>0)
                    fila.push({i,j-1});
                if(j<(M-1))
                    fila.push({i,j+1});
            }
        }
    }

    for(short int i=0; i<N; i++){
        for(short int j=0; j<M; j++)
            std::cout<<grid[i][j];
        std::cout<<'\n';
    }
        
    return 0;
}
