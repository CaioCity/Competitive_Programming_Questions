// https://atcoder.jp/contests/abc362/tasks/abc362_c
// Sum = 0

#include <bits/stdc++.h>

#define int int64_t

int32_t main() {

    std::ios::sync_with_stdio(0); std::cout.tie(0), std::cin.tie(0);

    int N,min=0,max=0;
    std::cin>>N;

    std::pair<int,int> duplas[N];

    for(int i=0; i<N; ++i){
        std::cin>>duplas[i].first>>duplas[i].second;
        min+=duplas[i].first; 
        max+=duplas[i].second;
    }

    if(!(min<=0 && 0<=max))
        std::cout<<"No\n";
    else{
        std::cout<<"Yes\n";
        int falta = 0 - min;
        for(int i = 0; i<N; ++i){
            if(falta>0){
                auto [L,R] = duplas[i];
                if(falta >= (R-L)){
                    falta-=(R-L);
                    std::cout<<R<<' ';
                }
                else if(falta < (R-L) ){
                    std::cout<<L+falta<<' ';
                    falta = 0;
                }
            }   
            else std::cout<<duplas[i].first<<' ';
        }
        std::cout<<'\n';
    }


    return 0;
}
