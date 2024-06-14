// https://neps.academy/br/exercise/1659
// Sanduiche

#include <bits/stdc++.h>

int main() {

    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);

    int N,M;
    int pot=1,A,B,aux,ans=0;
    bool next=0;

    std::cin>>N>>M;

    for(int i=0; i<N; i++)
        pot*=2;

    if(M==0){
        std::cout<<pot-1<<'\n';
        return 0;
    }

    bool* fator = (bool*)calloc(N,sizeof(bool));
    std::pair<int,int> V[M];
    for(int i=0; i<M; i++){
        std::cin>>A>>B;
        V[i]={A,B};
    }

    pot--;
    while(pot>0){
        aux=pot--;
        for(int i=0; i<N; i++){
            fator[i]=aux&1;
            aux=aux>>1;
        }

        next=0;
        for(auto [A,B] : V)
            if(fator[A-1] && fator[B-1]){
                next=1;
                break;
            }

        if(!next)
            ans++; 
    }

    std::cout<<ans<<'\n';

    return 0;
}
