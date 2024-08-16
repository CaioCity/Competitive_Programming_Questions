// https://neps.academy/br/competition/2006/exercise/2738
// A - Pedras

#include <bits/stdc++.h>

#define int int64_t

int32_t main (){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N;
    std::cin>>N;

    if(N%3 == 2)
        std::cout<<"Enzo\n";
    else std::cout<<"Lalic\n";

    return 0;
}
