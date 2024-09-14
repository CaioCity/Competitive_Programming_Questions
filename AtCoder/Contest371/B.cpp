// https://atcoder.jp/contests/abc371/tasks/abc371_b
// B - Taro

#include <bits/stdc++.h>

#define int int64_t
#define DEBUG(x) std::cout<<#x<<" = "<<x<<'\n';
const int INF = 1ll<<55;
// int mx[4] = {1,0,-1,0}, my[4] = {0,1,0,-1};

int32_t main(){

    // std::ios::sync_with_stdio(0),std::cin.tie(0);

    int N,M,F;
    char G;
    scanf("%lld %lld", &N, &M);

    std::unordered_set<int> S;
    for(int i=0; i<M; ++i){
        scanf("%d %c", &F,&G);
        if(G=='M' && S.find(F)==S.end()){
            S.insert(F);
            printf("Yes\n");
        } else printf("No\n");
    }

    return 0;
}
