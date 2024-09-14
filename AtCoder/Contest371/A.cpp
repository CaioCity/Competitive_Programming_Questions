// https://atcoder.jp/contests/abc371/tasks/abc371_a
// A - Jiro

#include <bits/stdc++.h>

#define int int64_t
#define DEBUG(x) std::cout<<#x<<" = "<<x<<'\n';
const int INF = 1ll<<55;
// int mx[4] = {1,0,-1,0}, my[4] = {0,1,0,-1};

int32_t main(){

    // std::ios::sync_with_stdio(0),std::cin.tie(0);

    std::string S;
    std::getline(std::cin,S);
    char AB,AC,BC;
    AB = S[0], AC = S[2], BC = S[4];

    if((AB=='<' && BC=='<') || (AB=='>' && BC=='>'))
        std::cout<<"B\n";
    else if((AB=='>' && AC=='<') || (AB=='<' && AC=='>'))
        std::cout<<"A\n";
    else std::cout<<"C\n";

    return 0;
}
