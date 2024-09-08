// https://atcoder.jp/contests/abc370/tasks/abc370_b
// B - Binary Alchemy

#include <bits/stdc++.h>

#define DEBUG(X) std::cout<<#X<<" = "<<X<<'\n';
#define int int64_t
const int INF = 1ll<<56;

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N;
    std::cin>>N;

    std::vector<std::vector<int>> grid (N+2, std::vector<int> (N+2));

    for(int i=1; i<=N; ++i)
        for(int j=1; j<=i; ++j)
            std::cin>>grid[i][j];

    int curr=1;

    for(int i=1; i<=N; ++i){
        if(curr>=i)
            curr = grid[curr][i]; 
        else curr = grid[i][curr];
    }

    std::cout<<curr<<'\n';

    return 0;
}
