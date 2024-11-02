// https://atcoder.jp/contests/abc378/tasks/abc378_b
// B - Garbage Collection

#include <bits/stdc++.h>

#define int int64_t
const int INF = 1ll<<40;
#define DEBUG(X) std::cout<<#X<<" = "<<X<<'\n';

int32_t main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0);

    int N,Q,T,D,diff;
    std::cin>>N;

    int G[N+1][2];

    for(int i=1; i<=N; ++i)
        std::cin>>G[i][0]>>G[i][1];

    std::cin>>Q;

    for(int i=0; i<Q; ++i){
        std::cin>>T>>D;
        diff = G[T][1] - D%G[T][0];
        if(diff<0)
            std::cout<<D+diff+G[T][0]<<'\n';
        else std::cout<<D+diff<<'\n';
    }
  
    return 0;
}
