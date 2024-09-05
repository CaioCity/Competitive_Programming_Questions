// https://codeforces.com/contest/2009/problem/C
// C - The Legend of Freya the Frog

#include <bits/stdc++.h>

#define int int64_t
const int INF = 1ll<<55;

void solve(){
   
    int x,y,k;
    std::cin>>x>>y>>k;

    int my = y/k, mx = x/k;

    if(y%k!=0)
        ++my;
    if(x%k!=0)
        ++mx;

    if(my==mx)
        std::cout<<(mx<<1)<<'\n';
    else if(my>mx)
        std::cout<<(my<<1)<<'\n';
    else /* (my<mx) */ 
        std::cout<<(mx<<1)-1<<'\n'; 
    
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
