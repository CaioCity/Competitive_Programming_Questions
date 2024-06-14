// https://codeforces.com/contest/1985/problem/D
// Manhattan Circle

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int T,N,M;
    std::cin>>T;
    while(T--){
        int N,M,C,L,maior=0,curr;
        std::cin>>N>>M;

        char grid[N][M];

        for(int i=0; i<N; i++){
            curr=0;
            for(int j=0; j<M; j++){
                std::cin>>grid[i][j];
                if(grid[i][j]=='#')
                    curr++;
            }
            if(maior<curr){
                maior=curr;
                L=i;
            }
        }

        maior=0;
        for(int j=0; j<M; j++){
            curr=0;
            for(int i=0; i<N; i++)
                if(grid[i][j]=='#')
                    curr++;
            if(maior<curr){
                maior=curr;
                C=j;
            }
        }

        std::cout<<L+1<<' '<<C+1<<'\n';
    }

    return 0;
}
