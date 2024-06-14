// https://neps.academy/br/exercise/65
// Mina

#include <bits/stdc++.h>

bool valid (short int a, short int b, short int N);

typedef std::tuple<short int, short int, short int> trio;

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    short int N,i,j,C;    
    std::cin>>N;

    bool grid[N][N];
    short int my[4]={1,0,-1,0}, mx[4]={0,1,0,-1};
    std::vector<std::vector<char>> visited (N, std::vector<char> (N,'0'));

    for(i=0; i<N; i++)
        for(j=0; j<N; j++)
            std::cin>>grid[i][j];

    std::priority_queue<trio, std::vector<trio>, std::greater<trio>> fila; 
    fila.push({0,0,0});

    while( !fila.empty() ){
    
        std::tie(C,i,j)=fila.top();
        fila.pop();

        if( i==(N-1) && j==(N-1) ){
            std::cout<<C<<'\n';
            return 0;
        }
    
        if(visited[i][j]=='1')
            continue;
        visited[i][j]='1';

        for(short int k=0,a,b; k<4; k++){
            a=i+my[k];
            b=j+mx[k];
            if(valid(a,b,N))
                fila.push({C+grid[a][b],a,b});                
        }
    }

    return 0;
}

bool valid (short int a, short int b, short int N){
    if( a>=0 && a<N && b>=0 && b<N )
        return true;
    return false;
}
