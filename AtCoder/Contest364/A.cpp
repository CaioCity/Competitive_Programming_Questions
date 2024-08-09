// https://atcoder.jp/contests/abc364/tasks/abc364_a
// A - Glutton Takahashi

#include <bits/stdc++.h>

#define int int64_t

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    std::string S;
    int N;
    bool sweet=0,dish;
    
    std::cin>>N;

    for(int i=0; i<N; ++i){
        std::cin>>S;
        if(S=="sweet"){
            if(sweet && i!=N-1){
                std::cout<<"No\n";
                return 0;
            }
            sweet=1;
        }
        else sweet=0;
    }
    
    std::cout<<"Yes\n";

    return 0;
}
