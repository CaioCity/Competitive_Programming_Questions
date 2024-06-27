// https://leetcode.com/problems/largest-local-values-in-a-matrix/description/
// 2373 - Largest Local Values in a Matrix

class Solution {
public:
    int nonao(int i,int j, vector<vector<int>>& grid){
        int num=0;
        num=max(grid[i][j],max(grid[i+1][j], max(grid[i-1][j], max(grid[i][j-1],grid[i][j+1]))));
        num=max(num, max(grid[i+1][j+1],max(grid[i-1][j+1],max(grid[i+1][j-1],grid[i-1][j-1]))));
        return num;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector <vector<int>> answer (n-2, vector<int> (n-2));
        for(int i=1; i<(n-1); i++)
            for(int j=1; j<(n-1); j++)
                answer[i-1][j-1]=nonao(i,j,grid);
        
        return answer;
    }
};
