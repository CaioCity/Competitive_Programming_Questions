// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-i/
// 3195 - Find the Minimum Area to Cover All Ones I

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int left=1200, right=0, cima=1200, baixo=0;
        int n=grid.size(), m=grid[0].size();
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; j++)
                if(grid[i][j]){
                    left=std::min(j,left);
                    right=std::max(j,right);
                    cima=std::min(i,cima);
                    baixo=i;
                }
        return (right - left + 1)*(baixo - cima + 1);
    }
};
