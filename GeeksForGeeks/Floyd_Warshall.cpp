// https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// Floyd-Warshall

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int N = matrix.size();  
	    
	    for(int k=0; k<N; ++k)
            for(int i=0; i<N; ++i)
                for(int j=0; j<N; ++j){
                    if(matrix[i][k]<0 || matrix[k][j]<0)
                        continue;
                    if(matrix[i][j]<0)
                        matrix[i][j] = matrix[i][k]+matrix[k][j];
	                else matrix[i][j] = std::min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                }
	}
};
