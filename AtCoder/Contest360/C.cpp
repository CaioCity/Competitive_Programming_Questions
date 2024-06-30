// https://atcoder.jp/contests/abc360/tasks/abc360_c
// Move It

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N;
    std::cin>>N;

    std::unordered_map<int,std::vector<int>> Box;
    int ans=0, Peso[N], tam;

    for(int i=0,aux; i<N; ++i){
        std::cin>>aux;
        Box[aux].push_back(i);
    }

    for(int i=0; i<N; ++i)
        std::cin>>Peso[i];

    for(auto [box, V] : Box){
        tam=V.size();
        if(tam>1){
            int index=0,aux=0;
            for(int i=0; i<tam; ++i){
                if(aux<Peso[V[i]]){
                    aux=Peso[V[i]];
                    index=i;
                }
                ans+=Peso[V[i]];
            }
            ans-=Peso[V[index]];
        }
    }
    
    std::cout<<ans<<'\n';

    return 0;
}
