// https://codeforces.com/contest/1978/problem/B
// New Bakery

#include <bits/stdc++.h>

int64_t n,a,b;

int64_t f(int64_t k);

int main() {

    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);

    int64_t t,ans,max,lim;

    std::cin>>t;

    while(t--){
        std::cin>>n>>a>>b;
        lim=std::min(n,b);
        max=b-a;
        ans=0;
        if(max>=lim)
            ans=f(lim);
        else if(max<0)
            ans=f(0);
        else ans=std::max(f(max),f(max+1));
        std::cout<<ans<<'\n';
    }

    return 0;
}

int64_t f(int64_t k){
    return (a*n + k*(b+1-a)-(k*(k+1))/2);
}
