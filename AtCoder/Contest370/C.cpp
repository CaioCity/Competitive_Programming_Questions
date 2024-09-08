// https://atcoder.jp/contests/abc370/tasks/abc370_c
// C - Word Ladder

#include <bits/stdc++.h>

#define DEBUG(X) std::cout<<#X<<" = "<<X<<'\n';
#define int int64_t
const int INF = 1ll<<56;

int32_t main(){

    // std::ios::sync_with_stdio(0), std::cin.tie(0);

    std::string S,T;
    std::vector<std::string> ans;
    std::cin>>S>>T;

    bool next;
    int tam = S.size();
    int back = 0, front = tam-1;
    S.push_back('\n');
    T.push_back('\n');

    while(S!=T){
        next = 0;
        for(; back<tam; ++back)
            if(S[back]>T[back]){
                S[back] = T[back];
                ans.push_back("a");
                ans.back() = S;
                next=1;
                break;
            } 

        if(next)
            continue;

        for(; front>=0; --front)
            if(S[front]!=T[front]){
                S[front] = T[front];
                ans.push_back("a");
                ans.back() = S;
                break;
            }
    }

    std::cout<<ans.size()<<'\n';
    for(std::string& str : ans)
        std::cout<<str;

    return 0;
}
