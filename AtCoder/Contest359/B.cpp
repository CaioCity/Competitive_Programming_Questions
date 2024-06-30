// https://atcoder.jp/contests/abc359/tasks/abc359_b
// Couples

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    short int N,ans=0;
    std::cin>>N;
    std::vector<short int> V(N);
    
    for(int i=0; i<(N<<1); i++)
        std::cin>>V[i];
    
    N=(N<<1)-2;
    for(int i=0; i<N; i++)
        if(V[i] == V[i+2])
            ans++;

    std::cout<<ans<<'\n';

    return 0;
}
