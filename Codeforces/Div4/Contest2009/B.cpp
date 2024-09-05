// https://codeforces.com/contest/2009/problem/B
// B - osu!mania

#include <bits/stdc++.h>

#define int int64_t
const int INF = 1ll<<55;

void solve(){
   
    int N;
    std::string S;
    std::cin>>N;

    std::stack<int> pilha;

    for(int ans, line = 0; line < N; ++line){
        ans = 1;
        std::cin>>S;

        for(char c : S)
            if(c=='#')
                break;
            else ++ans;
        
        pilha.push(ans);
    }

    while(!pilha.empty()){
        std::cout<<pilha.top()<<' ';
        pilha.pop();
    }

    std::cout<<'\n';

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
