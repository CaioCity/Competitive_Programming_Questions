// https://leetcode.com/problems/count-sub-islands/description/
// Count Sub Islands

class Solution {
public:

    bool sub (vector<vector<int>>& grid, vector<pair<int,int>>& island){
        for(auto [i,j]: island)
            if(!grid[i][j])
                return false;
            
        return true;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size(),n=grid1[0].size(),answer=0,a,b,aaux,baux;
        int mx[4]={1,0,-1,0},my[4]={0,1,0,-1};
        queue<pair<int,int>> fila;
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid2[i][j]){
                    fila.push({i,j});
                    vector<pair<int,int>> island;
                    while(!fila.empty()){ //bfs
                        a=fila.front().first;
                        b=fila.front().second;
                        fila.pop();
                        if(grid2[a][b]==0)
                            continue;
                        island.push_back({a,b});  
                        grid2[a][b]=0;
                        for(int k=0; k<4; k++){
                            aaux=a+mx[k];
                            baux=b+my[k];
                            if( aaux>=0 && aaux<m && baux>=0 && baux<n )
                                if(grid2[aaux][baux])
                                    fila.push({aaux,baux});
                        }
                    }
                    if(sub(grid1,island))
                        answer++;
                }
        return answer;
    }
};
