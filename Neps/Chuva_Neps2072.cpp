// https://neps.academy/br/exercise/2072
// Chuva (OBI 2022)

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int N,S,sum=0,ans=0;
    std::cin>>N>>S;
    int V[N];
    std::unordered_map<int,int> sums;

    for(int i=0; i<N; i++)
        std::cin>>V[i];

    for(int i=0; i<N; i++){
        sum+=V[i];
        if(sum==S)
            ans++;
        if(sums.find(sum-S)!=sums.end())
            ans+=sums[sum-S];
        sums[sum]++;
    }
    
    std::cout<<ans<<'\n';

    return 0;
}
