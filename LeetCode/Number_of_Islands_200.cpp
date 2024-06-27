// https://leetcode.com/problems/number-of-islands/description/
// 200 - Number of Islands

class Solution {
public:
    void define_ilha(short int i, short int j, vector<vector<char>>& grid) {
        queue<pair<short int, short int>> fila;
        fila.push(make_pair(i, j));

        while (!(fila.empty())) {
            short int a = fila.front().first, b = fila.front().second;
            fila.pop();
            if(grid[a][b]=='1'){
                grid[a][b] = '0';
                short int y = grid.size()-1, x = grid[0].size()-1;
                if(b<x)
                    if (grid[a][b + 1]=='1')
                        fila.push(make_pair(a, (b + 1)));
                if(b>0)
                    if (grid[a][b - 1]=='1')
                        fila.push(make_pair(a, (b - 1)));
                if(a<y)
                    if (grid[a + 1][b]=='1')
                        fila.push(make_pair((a + 1), b));
                if(a>0)
                    if (grid[a - 1][b]=='1')
                        fila.push(make_pair((a - 1), b));
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int ilhas = 0;
        short int y = grid.size(), x = grid[0].size();

        for (short int i = 0; i < y; i++)
            for (short int j = 0; j < x; j++)
                if (grid[i][j]=='1') {
                    ilhas++;
                    define_ilha(i, j, grid);
                    j++;
                }

        return ilhas;
    }
};
