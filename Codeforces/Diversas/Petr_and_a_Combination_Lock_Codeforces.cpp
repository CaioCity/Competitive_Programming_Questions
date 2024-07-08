// https://codeforces.com/problemset/problem/1097/B
// Petr and a Combination Lock

#include <bits/stdc++.h>

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,pot2=1,pot,aux=1;
    std::cin>>N;

    int V[N];
    for(int i=0; i<N; ++i) 
        std::cin>>V[i];

    pot2<<=N;

    while(--pot2>0){
        int sum=0;
        for(int i=0; i<N; ++i){
            if(pot2&(1<<i))
                sum+=V[i];
            else sum-=V[i];
        }
        if(sum%360==0){
            std::cout<<"YES\n";
            return 0;
        }
    }

    std::cout<<"NO\n";
    
    return 0;
}
