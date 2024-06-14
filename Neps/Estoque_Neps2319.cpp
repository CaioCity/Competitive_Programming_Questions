// https://neps.academy/br/exercise/2319
// Estoque

#include <bits/stdc++.h>

typedef std::pair<int64_t,int> duo;

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    short int N,M,P,ans=0,a,b;
    std::cin>>N>>M;

    short int grid[N][M];

    for(short int i=0; i<N; i++)
        for(short int j=0; j<M; j++)
            std::cin>>grid[i][j];

    std::cin>>P;
    while(P--){
        std::cin>>a>>b;
        a--; b--;
        if(grid[a][b]>0)
            ans++;
        grid[a][b]--;
    }

    std::cout<<ans<<'\n';

    return 0;
}
