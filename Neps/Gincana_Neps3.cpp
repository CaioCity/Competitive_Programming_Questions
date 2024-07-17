// https://neps.academy/br/exercise/3
// Gincana (OBI 2016)

#include <bits/stdc++.h>

#define int int64_t

int32_t main(){

    int gcd,N,M;
    std::cin>>N>>M;
    
    gcd = std::gcd(N,M);

    while(gcd!=1)
        gcd = std::gcd(N,--M);

    std::cout<<M<<'\n';

    return 0;
}
