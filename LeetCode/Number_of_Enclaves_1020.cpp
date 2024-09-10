// https://leetcode.com/problems/number-of-enclaves/description/
// 1020 - Number of Enclaves

class Solution {
public:
    bool valid(int i,int x, int y, int L, int C, int mx[], int my[]){
        x += mx[i];
        y += my[i];
        if(x>=0 && x<L && y>=0 && y<C)
            return 1;
        return 0;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int mx[] = {1,0,-1,0}, my[] = {0,1,0,-1};
        int L = grid.size(), C = grid[0].size(),x,y;

        for(int i=0; i<C; ++i)
            if(grid[0][i]){
                queue<pair<int,int>> fila;
                fila.push({0,i});
                while(!fila.empty()){
                    tie(x,y) = fila.front();
                    fila.pop();
                    if(!grid[x][y])
                        continue;
                    grid[x][y] = 0;
                    for(int j=0; j<4; ++j)
                        if(valid(j,x,y,L,C,mx,my) && grid[x+mx[j]][y+my[j]])
                            fila.push({x+mx[j],y+my[j]});
                }
            }
        for(int i=0; i<C; ++i)
            if(grid[L-1][i]){
                queue<pair<int,int>> fila;
                fila.push({L-1,i});
                while(!fila.empty()){
                    tie(x,y) = fila.front();
                    fila.pop();
                    if(!grid[x][y])
                        continue;
                    grid[x][y] = 0;
                    for(int j=0; j<4; ++j)
                        if(valid(j,x,y,L,C,mx,my) && grid[x+mx[j]][y+my[j]])
                            fila.push({x+mx[j],y+my[j]});
                }
            }
        for(int i=0; i<L; ++i)
            if(grid[i][0]){
                queue<pair<int,int>> fila;
                fila.push({i,0});
                while(!fila.empty()){
                    tie(x,y) = fila.front();
                    fila.pop();
                    if(!grid[x][y])
                        continue;
                    grid[x][y] = 0;
                    for(int j=0; j<4; ++j)
                        if(valid(j,x,y,L,C,mx,my) && grid[x+mx[j]][y+my[j]])
                            fila.push({x+mx[j],y+my[j]});
                }
            }
        for(int i=0; i<L; ++i)
            if(grid[i][C-1]){
                queue<pair<int,int>> fila;
                fila.push({i,C-1});
                while(!fila.empty()){
                    tie(x,y) = fila.front();
                    fila.pop();
                    if(!grid[x][y])
                        continue;
                    grid[x][y] = 0;
                    for(int j=0; j<4; ++j)
                        if(valid(j,x,y,L,C,mx,my) && grid[x+mx[j]][y+my[j]])
                            fila.push({x+mx[j],y+my[j]});
                }
            }
        
        int ans = 0;
        for(int i=0; i<L; ++i)
            for(int j=0; j<C; ++j)
                if(grid[i][j])
                    ++ans;
        return ans;
    }
};
