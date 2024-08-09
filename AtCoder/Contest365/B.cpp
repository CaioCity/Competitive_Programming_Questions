// https://atcoder.jp/contests/abc365/tasks/abc365_b
// B - Second Best

#include <bits/stdc++.h>

#define int int64_t

int32_t main (){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N,aux;
    std::cin>>N;

    std::map<int,int> mapa;

    for(int i=0; i<N; ++i){
        std::cin>>aux;
        mapa[aux] = i;
    }

    auto it = mapa.end();
    --it, --it;
   
    std::cout<<it->second +1<<'\n';

    return 0;
}
