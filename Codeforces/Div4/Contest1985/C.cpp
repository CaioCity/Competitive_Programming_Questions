// https://codeforces.com/contest/1985/problem/C
// Good Prefixes

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        int n,maior=0,aux,ans=0;
        long long sum=0;
        std::cin>>n;
        for(int i=0; i<n; i++){
            std::cin>>aux;
            sum+=aux;
            maior=std::max(maior,aux);
            if(maior==(sum-maior))
                ans++;                
        }
        std::cout<<ans<<'\n';
    }

    return 0;
}
