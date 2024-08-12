// https://codeforces.com/contest/1999/problem/E
// E - Triple Operations

#include <bits/stdc++.h>

int64_t l,r,ans,i,j;

int64_t pot[16] = {1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907};

void solve();

int32_t main (){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int64_t t;
        
    std::cin>>t;

    while(t--)
        solve();

    return 0;
}

void solve(){
	ans=0;
    std::cin>>l>>r;

    for(j=0; pot[j]<=l; ++j);
	ans+=j;

    ans<<=1;

    for(int i=l+1; i<=r;){
        ans+= (j*(std::min(pot[j],r+1) - i));
        i = pot[j++];
    }
        
   std::cout<<ans<<'\n';
}
