// https://atcoder.jp/contests/abc371/tasks/abc371_d
// D - 1D Country

#include <bits/stdc++.h>

#define int int64_t
#define DEBUG(x) std::cout<<#x<<" = "<<x<<'\n';
const int INF = 1ll<<55;
// int mx[4] = {1,0,-1,0}, my[4] = {0,1,0,-1};

int32_t main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0);

    int N,Q,S,E;
    std::vector<int>::iterator start,end;
    std::cin>>N;

    std::vector<int> V(N), P(N);
    for(int i=0; i<N; ++i)
        std::cin>>V[i];

    std::cin>>P[0];
    for(int i=1; i<N; ++i){
        std::cin>>P[i];
        P[i]+=P[i-1];
    }

    std::cin>>Q;
    while(Q--){
        std::cin>>S>>E;
        start = std::lower_bound(V.begin(),V.end(),S);
        end = std::lower_bound(V.begin(), V.end(), E);
        
        if(S>V[N-1] || E<V[0]){
            std::cout<<0<<'\n';
            continue;
        }

        if(E>V[N-1]){
            if(start == V.begin())
                std::cout<<P[N-1]<<'\n';
            else std::cout<<P[N-1] - P[start-V.begin()-1]<<'\n';
            continue;
        }

        if(*end != E)
            --end;
        
        if(start == V.begin())
            std::cout<<P[end - V.begin()]<<'\n';
        else std::cout<<P[end-V.begin()]-P[start-V.begin()-1]<<'\n';
    }

    return 0;
}
