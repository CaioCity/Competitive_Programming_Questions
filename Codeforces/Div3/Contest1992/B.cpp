// https://codeforces.com/contest/1992/problem/B
// Angry Monk

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int t,N,K;

    std::cin>>t;

    while(t--){

        std::cin>>N>>K;
        
        int max=0, n_cortes=0, sum=0, pieces[K];

        for(int i=0; i<K; ++i){
            std::cin>>pieces[i];
            if(pieces[i]!=1)
                n_cortes+=pieces[i]-1;
            max=std::max(max,pieces[i]);
        }

        if(max!=1)
            n_cortes-=(max-1);

        std::cout<<n_cortes+(N-max)<<'\n';
    }

    return 0;
}
