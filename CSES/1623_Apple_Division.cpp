// https://cses.fi/problemset/task/1623/
// Apple Division

#include <bits/stdc++.h>

#define int long long

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,A=0,B=0, pot=1, ans=INT64_MAX;
    std::cin>>N;

    pot<<=N;
    int apple[N];

    for(int i=0; i<N; ++i)
        std::cin>>apple[i];
    
    while(--pot){
        A=0,B=0;
        for(int i=0; i<N; ++i){
            if(1<<i & pot)
                B+=apple[i];
            else A+=apple[i];
        }
        ans=std::min(ans, std::abs(A-B));
    }

    std::cout<<ans<<'\n';

    return 0;
}
