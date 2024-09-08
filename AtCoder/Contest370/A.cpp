// https://atcoder.jp/contests/abc370/tasks/abc370_a
// A - Raise Both Hands

#include <bits/stdc++.h>

#define DEBUG(X) std::cout<<#X<<" = "<<X<<'\n';
#define int int64_t
const int INF = 1ll<<56;

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    bool L,R;
    std::cin>>L>>R;

    if(L ^ R){
        if(L)
            std::cout<<"Yes\n";
       else std::cout<<"No\n";
    } else std::cout<<"Invalid\n";

    return 0;
}
