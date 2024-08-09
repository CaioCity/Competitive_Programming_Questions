// https://codeforces.com/contest/1999/problem/D
// D - Slavic's Exam

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
    
    std::string S,T;

    std::cin>>S>>T;

    int tamS = S.size(), j=T.size()-1, i;

    for(i=tamS; i>=0 && j!=-1; --i){
        if(S[i]==T[j])
            --j;
        if(S[i]=='?'){
            S[i]=T[j];
            --j;
        }
    }
    
    while(i>=0){
        if(S[i]=='?')
            S[i]='a';
        --i;    
    }

    if(j==-1)
        std::cout<<"YES\n"<<S<<'\n';
    else std::cout<<"NO\n";

    return;
}
