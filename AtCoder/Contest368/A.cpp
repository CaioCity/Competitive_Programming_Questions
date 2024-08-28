// https://atcoder.jp/contests/abc368/tasks/abc368_a
// A - Cut

#include <bits/stdc++.h>

#define int int64_t

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N,K;
    std::cin>>N>>K;

    int V[N];
    for(int i=K; i<N; ++i)
        std::cin>>V[i];
    for(int i=0; i<K; ++i)
        std::cin>>V[i];
    
    for(int i=0; i<N; ++i) 
        std::cout<<V[i]<<' ';
    std::cout<<'\n';

    return 0;
}
