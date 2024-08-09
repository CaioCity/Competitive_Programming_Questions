// https://codeforces.com/contest/1999/problem/A
// A+B Again?

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
    int x;
    std::cin>>x;
    std::cout<<x%10 + x/10<<'\n';
}
