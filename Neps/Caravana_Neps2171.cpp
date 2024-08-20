// https://neps.academy/br/exercise/2171
// Caravana - OBI F3 2022

#include <bits/stdc++.h>

#define int int64_t

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N,sum = 0;
    std::cin>>N;

    int C[N];

    for(int i=0; i<N; ++i){
        std::cin>>C[i];
        sum+=C[i];
    }

    sum /= N;

    for(int i=0; i<N; ++i)
        std::cout<<sum-C[i]<<'\n';

    return 0;
}
