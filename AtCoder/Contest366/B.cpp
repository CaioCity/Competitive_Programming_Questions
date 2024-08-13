// https://atcoder.jp/contests/abc366/tasks/abc366_b
// B - Vertical Writing

#include <bits/stdc++.h>

#define int int64_t

int32_t main (){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N,M=0;
    std::cin>>N;

    std::vector<std::string> grid(N);

    for(int i=0; i<N; ++i){
        std::cin>>grid[i];
        M = std::max(M , (int)grid[i].size());
    }

    std::vector<std::string> ans (M,std::string(N+1,' '));

    for(int i = N-1; i>=0; --i){
        int t = grid[i].size();
        for(int j=0; j<t; ++j)
            ans[j][N-i-1] = grid[i][j];        
    }

    int j;
    for(int i = M-1; i>=0; --i){
        for(j=N-1; j>=0; --j)
            if(ans[i][j]!=' ')
                break;
        for(--j; j>=0; --j)
            if(ans[i][j]==' ')
                ans[i][j]='*';        
    }

    for(int i =0; i<M; ++i)
        std::cout<<ans[i]<<'\n';

    return 0;
}
