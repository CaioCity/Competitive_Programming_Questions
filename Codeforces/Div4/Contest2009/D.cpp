// https://codeforces.com/contest/2009/problem/D
// D - Satyam and Counting

#include <bits/stdc++.h>

#define int int64_t
const int INF = 1ll<<55;

void solve(){
   
    int N,x,y,ans=0;
    std::cin>>N;

    std::set<int> top, down;

    for(int i=0; i<N; ++i){
        std::cin>>x>>y;
        if(y) top.insert(x);
        else down.insert(x);
    }

    for(int P : top){
        if(down.find(P)!=down.end())
            ans+=(top.size() + down.size() - 2);
        if(down.find(P-1)!=down.end() && down.find(P+1)!=down.end())
            ++ans;
    }

    for(int P : down)
        if(top.find(P-1)!=top.end() && top.find(P+1)!=top.end())
            ++ans;
    
    std::cout<<ans<<'\n';

    return;
}

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int t;
    std::cin>>t;

    while(t--)
        solve();

    return 0;
}
