// https://atcoder.jp/contests/abc368/tasks/abc368_b
// B - Decrease 2 max elements

#include <bits/stdc++.h>

#define int int64_t

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N,ans=0;
    std::cin>>N;    

    int V[N];
    for(int i=0; i<N; ++i)
        std::cin>>V[i];
    
    std::sort(V,V+N,std::greater<int>());

    int aux,index = 0;
    while( V[1]!=0){
        V[0]-=V[1];
        ans+=V[1];
        V[1] = 0;
        std::sort(V,V+N-index,std::greater<int>());
        ++index;
    }

    std::cout<<ans<<'\n';

    return 0;
}
