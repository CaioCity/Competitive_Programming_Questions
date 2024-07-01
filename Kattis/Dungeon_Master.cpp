// https://open.kattis.com/problems/dungeon
// Dungeon Master 
// BFS 3D

#include <bits/stdc++.h>

typedef std::tuple<int,int,int,int> quadra;

int movex[6]={1,0,-1,0,0,0}, movez[6]={0,1,0,-1,0,0}, movey[6]={0,0,0,0,1,-1};

int main() {

    // std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    while(1){
        int L, R, C;
        std::cin>>L>>R>>C;

        if(L==R && R==C && C==0)
            break;

        char grid[L][R][C];

        for(int i=0; i<L; ++i)
            for(int j=0; j<R; ++j)
                scanf(" %s", grid[i][j]);

        std::queue<quadra> fila;
        
        for(int i=0; i<L; ++i)
            for(int j=0; j<R; ++j)
                for(int k=0; k<C; ++k)
                    if(grid[i][j][k]=='S')
                        fila.push({0,i,j,k});

        int X,Y,Z, time;
        while(!fila.empty()){
            // std::cout<<fila.size()<<" = size\n";
            std::tie(time,Y,Z,X)=fila.front();
            
            if(grid[Y][Z][X]=='E'){
                std::cout<<"Escaped in "<<time<<" minute(s).\n";
                break;
            }

            fila.pop();

            if(grid[Y][Z][X]=='#')
                continue;
                
            grid[Y][Z][X]='#';

            for(int i=0; i<6; ++i)
                if( (Y+movey[i])>=0 && (Y+movey[i])<L 
                 && (Z+movez[i])>=0 && (Z+movez[i])<R 
                 && (X+movex[i])>=0 && (X+movex[i])<C 
                 && grid[Y+movey[i]][Z+movez[i]][X+movex[i]]!='#' )
                    fila.push({time+1, Y+movey[i], Z+movez[i], X+movex[i]});

        }

        if(fila.empty())
            std::cout<<"Trapped!\n";

    }
    
    return 0;
}
