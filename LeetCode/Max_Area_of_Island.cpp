// https://leetcode.com/problems/max-area-of-island/description/
// Max Area of Island

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int answer=0,count=0,m=grid.size(),n=grid[0].size(),a,b,k;
        queue<pair<int,int>> fila;
        int my[4]={1,0,-1,0},mx[4]={0,1,0,-1};

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(grid[i][j]){
                    count=0;
                    fila.push({i,j});
                    while(!fila.empty()){
                        a=fila.front().first;
                        b=fila.front().second;
                        fila.pop();
                        if(grid[a][b]!=0){
                            count++;
                            for(k=0; k<4; k++)
                                if( (a+my[k])>=0 && (a+my[k])<m && (b+mx[k])>=0 && (b+mx[k])<n )
                                    fila.push({a+my[k],b+mx[k]});
                            grid[a][b]=0;
                        }
                    }
                    answer=(answer<count)? count : answer;
                }
            }
        return answer;
    }
};
