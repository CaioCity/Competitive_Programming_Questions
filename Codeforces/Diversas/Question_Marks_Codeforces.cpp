// https://codeforces.com/contest/1993/problem/A
// Question Marks

#include <bits/stdc++.h>

#define int int64_t

int32_t main (){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int t, N, ans;
    std::string S;
        
    std::cin>>t;

    while(t--){
        std::cin>>N;
        std::cin>>S;
        
        int itens[4]={0,0,0,0};

        for(char C : S)
            if(C!='?')
                ++itens[C-'A'];

        ans=0;

        for(int i=0; i<4; ++i){
            if(itens[i]>=N)
                ans+=N;
            else ans+=itens[i];
        }

        std::cout<<ans<<'\n';
    }

    return 0;
}
