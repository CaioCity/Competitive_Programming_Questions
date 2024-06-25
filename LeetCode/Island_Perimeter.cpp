// https://leetcode.com/problems/island-perimeter/description/
// Island Perimeter

class Solution {
public:
int x; 
    int islandPerimeter(vector<vector<int>>& grid) {
        int NL = grid.size();
        int NC = grid[0].size();
        int _2P=0;

        for(int i=0; i<NL; i++){
            for(int j=0; j<NC; j++){
                if(grid[i][j]==1){

                    if(i == 0  || (i>0 && !grid[i-1][j])){
                        _2P++;
                    }
                    if(i==(NL-1) || (i<(NL-1) && !grid[i+1][j])){
                        _2P++;
                    }
                    if(j==0 || (j>0 && !grid[i][j-1])){
                        _2P++;
                    }
                    if(j==(NC-1) || (j<(NC-1) && !grid[i][j+1])){
                        _2P++;
                    }

                }
            }
        }
        return _2P;
    }
};
