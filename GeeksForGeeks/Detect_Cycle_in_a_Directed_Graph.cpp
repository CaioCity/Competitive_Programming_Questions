// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1
// Detect Cycle in a Directed Graph
 
class Solution {
  public:
    bool dfs(int curr, int status[], vector<int> adj[]){
        switch(status[curr]){
            case 0:
                status[curr]=2;
                for(int T : adj[curr])
                    if(dfs(T,status,adj))
                        return 1;
                break;
            case 1: return 0;
            case 2: return 1;
        }
        status[curr]=1;
        return 0;
    }
    
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int* status = (int*)calloc(V,sizeof(int));
        for(int i = 0; i<V; ++i)
            if(!status[i] && dfs(i,status,adj))
                return 1;
        return 0;
    }
};
