// https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
// 2684 - Maximum Number of Moves in a Grid

class Solution {
public:
    int DP(int i, int j, vector<vector<int>>& mem, vector<vector<int>>& grid){
        if(mem[i][j]!=-1)
            return mem[i][j];
        
        if(j==grid[i].size()-1)
            return 0;

        mem[i][j] = 0;

        if(grid[i][j] < grid[i][j+1])
            mem[i][j] = 1 + DP(i,j+1,mem,grid);
        if(i<grid.size()-1 && grid[i][j] < grid[i+1][j+1])
            mem[i][j] = max(mem[i][j], 1 + DP(i+1,j+1,mem,grid));
        if(0<i && grid[i][j] < grid[i-1][j+1])
            mem[i][j] = max(mem[i][j], 1 + DP(i-1,j+1,mem,grid));
        
        return mem[i][j];
    }

    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> mem (m, vector<int>(n,-1));

        for(int i=0; i<m; ++i)
            ans = max(ans,DP(i,0,mem,grid));
            
        return ans;
    }
};
