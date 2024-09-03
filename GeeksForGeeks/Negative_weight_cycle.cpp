// https://www.geeksforgeeks.org/problems/negative-weight-cycle3504/1
// Negative weight cycle
// Consulta -> https://www.geeksforgeeks.org/detecting-negative-cycle-using-floyd-warshall/

class Solution {
public:
	int isNegativeWeightCycle(int N, vector<vector<int>>edges){
	    int INF = 1<<28;
	    int M = edges.size(), U,V,C;
	    vector<vector<int>> matrix (N, vector<int>(N,INF));
	    
	    for(int i=0; i<M; ++i){
	        U = edges[i][0], V = edges[i][1], C = edges[i][2];
	        matrix[U][V] = C;
	    }
	    
	    for(int k=0; k<N; ++k)
            for(int i=0; i<N; ++i)
                for(int j=0; j<N; ++j)
                    if(matrix[i][k]!=INF && matrix[k][j]!=INF)
                        matrix[i][j] = std::min(matrix[i][j], matrix[i][k]+matrix[k][j]);
                    
        for(int i=0; i<N; ++i)
            if(matrix[i][i]<0)
                return 1;
        return 0;
	}
};
