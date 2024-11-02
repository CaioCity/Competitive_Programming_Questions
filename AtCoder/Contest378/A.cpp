// https://atcoder.jp/contests/abc378/tasks/abc378_a
// A - Pairing

#include <bits/stdc++.h>

#define int int64_t
const int INF = 1ll<<40;
#define DEBUG(X) std::cout<<#X<<" = "<<X<<'\n';

int32_t main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0);

    int C,V[5],ans=0;

    for(int i=0; i<4; ++i){
        std::cin>>C;
        ++V[C];
    }

    for(int i=1; i<5; ++i){
        if(V[i]==4){
            std::cout<<2<<'\n';
            return 0;
        }
        if(V[i]>1)
            ++ans;
    }

    std::cout<<ans<<'\n';


    return 0;
}
