// https://neps.academy/br/exercise/2832
// Estante de Livros

#include <bits/stdc++.h>

#define int int64_t
#define DEBUG(x) std::cout<<#x<<" = "<<x<<'\n';
const int INF = 1ll<<55;
// int mx[4] = {1,0,-1,0}, my[4] = {0,1,0,-1};

int32_t main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0);

    int X,Y,Z,N;
    std::cin>>X>>Y>>Z>>N;

    std::cout<<(X+Y+Z)%N<<'\n';

    return 0;
}
