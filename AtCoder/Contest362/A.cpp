// https://atcoder.jp/contests/abc362/tasks/abc362_a
// Buy a Pen

#include <bits/stdc++.h>

int main() {

    std::ios::sync_with_stdio(0); std::cout.tie(0), std::cin.tie(0);

    int R,G,B;
    std::string C;
    std::cin>>R>>G>>B>>C;

    if(C=="Red")
        std::cout<<std::min(G,B)<<'\n';
    else if(C=="Green")
        std::cout<<std::min(R,B)<<'\n';
    else if(C=="Blue")
        std::cout<<std::min(G,R)<<'\n';

    return 0;
}
