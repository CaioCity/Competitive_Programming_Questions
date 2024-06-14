// https://neps.academy/br/exercise/58
// Chuva (OBI 2016)

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);

    int N,left,right;
    std::cin>>N;

    std::tuple<int,int,int> V[N]; // altura, esq, dir
    std::cin>>std::get<0>(V[0]);
    std::get<0>(V[1])=left=std::get<0>(V[0]);


    for(int i=1; i<N; i++){
        std::cin>>std::get<0>(V[i]);
        std::get<1>(V[i])=left;
        if(std::get<0>(V[i])>left)
            left=std::get<0>(V[i]);
    }

    right=std::get<0>(V[N-1]);
    std::get<2>(V[N-1])=right;
    for(int i=N-2; i>=0; i--){
        std::get<2>(V[i])=right;
        if(std::get<0>(V[i])>right)
            right=std::get<0>(V[i]);
    }
    int ans=0;
    for(auto [a,b,c] : V)
        if(a<b && a<c)
            ans++;
    
    std::cout<<ans<<'\n';

    return 0;
}
