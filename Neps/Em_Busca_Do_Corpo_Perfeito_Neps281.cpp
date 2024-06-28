// https://neps.academy/br/exercise/281
// Em Busca do Corpo Perfeito

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,P;
    std::cin>>P>>N;

    int peso[N+4], protein[N+4];
    peso[0]=protein[0]=0;

    int *last=(int*)calloc(P+10,sizeof(int)), *atual=(int*)calloc(P+10,sizeof(int));

    for(int i=1; i<=N; ++i)
        std::cin>>peso[i]>>protein[i];

    for(int i=0; i<=N; ++i){
        for(int j=1; j<=P; ++j){
            if(j-peso[i]<0)
                atual[j]=last[j];
            else atual[j]=std::max(last[j-peso[i]]+protein[i],last[j]);
        }
        std::swap(atual,last);
    }

    std::cout<<last[P]<<'\n';    

    return 0;
}
