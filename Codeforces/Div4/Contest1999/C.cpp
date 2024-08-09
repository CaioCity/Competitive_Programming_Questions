// https://codeforces.com/contest/1999/problem/C
// C - Showering

#include <bits/stdc++.h>

#define int int64_t

void solve();

int32_t main (){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int t;
        
    std::cin>>t;

    while(t--)
        solve();

    return 0;
}

void solve(){
    int n,s,m, t=0;
    std::cin>>n>>s>>m;

    std::pair<int,int> V[n];

    for(int i=0; i<n; ++i)
        std::cin>>V[i].first>>V[i].second;

    if(V[0].first>=s || m-V[n-1].second>=s){
        std::cout<<"YES\n";
        return;
    }

    for(int i=1; i<n; ++i){
        if(V[i].first - V[i-1].second >= s){
            std::cout<<"YES\n";
            return;
        }
    }

    std::cout<<"NO\n";

    return;
}
