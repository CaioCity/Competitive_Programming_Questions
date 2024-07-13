// https://atcoder.jp/contests/abc355/tasks/abc355_c
// Bingo 2

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    
    int T,pos;
    short int N;
    bool freio=0;
        
    std::cin>>N>>T;

    bool M[N+5][N+5];
    for(int i=0; i<(N+2); i++)
        for(int j=0; j<(N+3); j++)
            M[i][j]=0;

    for(int index=0; index<T; index++){
        std::cin>>pos;
        int L=floor(pos/N), C= ((pos%N)-1);
        if(C==(-1)){
            C=(N-1);
            L--;
        }
        
        M[L][C]=1;

        if( L == C ){ //se for diagonal principal
            int i,j;
            for( i=0, j=0; i<N && j<N; i++, j++)
                if(!M[i][j])
                    break;
            if(i==N && j==N){
                std::cout<<(index+1)<<'\n';
                return 0;
            }
        }

        if( (L+C)==(N-1) ){ //diagonal sec
            int i,j;
            for( i=(N-1), j=0; i>=0 && j<N; i--, j++)
                if(!M[i][j])
                    break;
            if(i==(-1) && j==N){
                std::cout<<(index+1)<<'\n';
                return 0;
            }
        }

        int i;
        for(i=0; i<N; i++)
            if(!M[i][C])
                break;
        if(i==N){
            std::cout<<(index+1)<<'\n';
            return 0;
        }

        int j;
        for(j=0; j<N; j++)
            if(!M[L][j])
                break;
        if(j==N){
            std::cout<<(index+1)<<'\n';
            return 0;
        }
    }

    std::cout<<"-1\n";

    return 0;
}
