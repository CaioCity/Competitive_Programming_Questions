// https://atcoder.jp/contests/abc361/tasks/abc361_c
// Make Them Narrow

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,K,ans=INT32_MAX;

    std::cin>>N>>K;

    if(N-1<=K){
        std::cout<<0<<'\n';
        return 0;
    }

    int V[N];

    for(int i=0; i<N; ++i)
        std::cin>>V[i];

    std::sort(V,V+N);

    for(int i=0, j=N-K-1; i<=K; ++i, ++j )
        ans=std::min(ans,V[j]-V[i]);
    
    std::cout<<ans<<'\n';

    return 0;
}
