// https://leetcode.com/problems/pascals-triangle/description/
// 118 - Pascal's Triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector <vector<int> > triangle;
        vector <int> linha1;
        linha1.push_back(1);
        triangle.push_back(linha1);
       
        for(int i=1; i < numRows; i++){
            vector <int> linha;
            linha.push_back(1);
            for(int j=1; j<i; j++){
                linha.push_back(triangle[i-1][j-1]+triangle[i-1][j]);
            }
            linha.push_back(1);
            triangle.push_back(linha);
        }
        return triangle;
    }
    
};
