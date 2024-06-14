// https://codeforces.com/contest/1985/problem/B
// Maximum Multiple Sum

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int T;
    std::cin>>T;
    while(T--){
        int n,maior=0,ans=0,aux;
        std::cin>>n;
        for(int x=2; x<=n; x++){
            aux=n/x;
            aux= ((aux*x + x)*aux)/2;
            if(aux>maior){
                maior=aux;
                ans=x;
            }
        }
        std::cout<<ans<<'\n';
    }

    return 0;
}
