// https://atcoder.jp/contests/abc378/tasks/abc378_d
// D - Count Simple Paths

#include <bits/stdc++.h>

#define int int64_t
const int INF = 1ll<<40;
#define DEBUG(X) std::cout<<#X<<" = "<<X<<'\n';
const int mx[]={1,0,-1,0}, my[]={0,1,0,-1};

int H,W,ans;

void dfs(int i, int j, int moves, std::vector<std::string> grid){
    for(int k=0; k<4; ++k)   
        if(0<=i+mx[k] && i+mx[k]<H && 0<=j+my[k] && j+my[k]<W && grid[i+mx[k]][j+my[k]]=='.'){
            if(moves==1) ++ans;
            else{
                grid[i][j]='#';
                dfs(i+mx[k],j+my[k],moves-1,grid);
                grid[i][j]='.';
            } 
        }
}

int32_t main(){

    std::ios::sync_with_stdio(0),std::cin.tie(0);

    int K;
    std::cin>>H>>W>>K;

    std::vector<std::string> grid(H);
    
    for(int i=0; i<H; ++i)
        std::cin>>grid[i];

    for(int i=0; i<H; ++i)
        for(int j=0; j<W; ++j)
            if(grid[i][j]=='.')
                dfs(i,j,K,grid);

    std::cout<<ans<<'\n';

    return 0;
}
