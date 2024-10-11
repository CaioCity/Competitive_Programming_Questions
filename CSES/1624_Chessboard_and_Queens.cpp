// https://cses.fi/problemset/task/1624/
// Chessboard and Queens

#include <bits/stdc++.h>
 
#define int int64_t
#define DEBUG(x) std::cout<<#x<<" = "<<x<<'\n';
const int INF = 1ll<<50;
// int mx[4] = {1,0,-1,0}, my[4] = {0,1,0,-1};
 
enum status { FREE, QUEEN, RESERVED };
 
void backtracking(int line, int& ans, bool cols[], std::vector<std::vector<int>>& grid);
 
bool in_attack(int L, int C, std::vector<std::vector<int>>& grid);
 
int32_t main(){
 
    std::ios::sync_with_stdio(0), std::cin.tie(0);
 
    int ans = 0;
    std::vector<std::string> str_grid (8);
    std::vector<std::vector<int>> grid (8, std::vector<int> (8,0));
 
    for(int i=0; i<8; ++i){
        std::cin>>str_grid[i];
        for(int j=0; j<8; ++j)
            if(str_grid[i][j]=='*')
                grid[i][j] = RESERVED;
    }
 
    bool cols[8] = {0};
 
    backtracking(0,ans,cols,grid);
 
    std::cout<<ans<<'\n';
 
    return 0;
}
 
void backtracking(int line, int& ans, bool cols[], std::vector<std::vector<int>>& grid){
    if(line == 8){
        ++ans;
        return;
    }
 
    for(int C=0; C<8; ++C){
        if(cols[C] || grid[line][C] != FREE || in_attack(line,C,grid))
            continue;
 
        grid[line][C] = QUEEN;
        cols[C] = 1;
        
        backtracking(line+1,ans,cols,grid);
    
        cols[C] = 0;
        grid[line][C] = FREE;
    }
    
}
 
bool in_attack(int L, int C, std::vector<std::vector<int>>& grid){
    for(int i=L-1,j=C+1; i>=0 && j<8; --i,++j)
        if(grid[i][j]==QUEEN)
            return 1;
 
    for(int i=L+1,j=C-1; i<8 && j>=0; ++i, --j)
        if(grid[i][j]==QUEEN)
            return 1;
 
    for(int i=L-1,j=C-1; i>=0 && j>=0; --i,--j)
        if(grid[i][j]==QUEEN)
            return 1;
            
    for(int i=L+1,j=C+1; i<8 && j<8; ++i, ++j)
        if(grid[i][j]==QUEEN)
            return 1;
 
    return 0;    
}
