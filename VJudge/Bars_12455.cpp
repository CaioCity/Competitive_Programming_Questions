// https://vjudge.net/problem/UVA-12455
// 12455 - Bars

#include <bits/stdc++.h>

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int t;
    std::cin>>t;

    while(t--){
        int target,N,pot2=1,pot,aux=1;
        std::cin>>target>>N;

        int V[N];
        for(int i=0; i<N; ++i) 
            std::cin>>V[i];

        pot2<<=N;
        bool ans=0;
        while(--pot2>0){
            int sum=0;
            for(int i=0; i<N; ++i){
                if(pot2&(1<<i))
                    sum+=V[i];
                if(sum>=target)
                    break;
            }
            if(sum==target){
                ans=1;
                std::cout<<"YES\n";
                break;
            }
        }
        if(!ans)
            std::cout<<"NO\n";
    }

    return 0;
}
