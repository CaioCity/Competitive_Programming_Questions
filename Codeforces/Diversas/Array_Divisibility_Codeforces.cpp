// https://codeforces.com/contest/1983/problem/A
// Array Divisibility

#include <bits/stdc++.h>

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int t,N;

    std::cin>>t;

    while(t--){
        std::cin>>N;
        int DP[N+1];
        
        for(int i=N, half=N>>1; i>half; --i)
            DP[i]=i;

        for(int i=N>>1; i>0; --i)
            for(int j=i<<1; j<=N; j+=i)
                DP[i]=i;

        for(int i=1; i<N; ++i)
            std::cout<<DP[i]<<' ';
        std::cout<<DP[N]<<'\n';
        
    }

    return 0;
}
