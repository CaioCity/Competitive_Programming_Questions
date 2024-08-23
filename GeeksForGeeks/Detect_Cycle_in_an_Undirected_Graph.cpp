// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
// Deteccao de ciclos em grafos nao direcionados

class Solution {
  public:
    
    int find(int A, int leader[]){
        if(A==leader[A])
            return A;
        return leader[A] = find(leader[A], leader);
    }
    
    void merge(int A, int B, int leader[], int conex[]){
        if(conex[A]>conex[B])
            swap(A,B);
        leader[B] = A;
        conex[A]+=conex[B];
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        
        // Tratamento de dados -> lista de adj para lista de arestas
        vector<pair<int,int>> edges;
        for(int i=0; i<V; ++i)
            for(auto C : adj[i])
                if(i<C)
                    edges.push_back({i,C});
        
        // Preparativos para a DSU
        int* conex = (int*)malloc(V*sizeof(int));
        int* leader = (int*)malloc(V*sizeof(int));
        for(int i=0; i<V; ++i){
            leader[i]=i;
            conex[i]=1;
        }
        
        int U,T;
        int tam = edges.size();
        
        for(int i=0; i<tam; ++i){
            tie(U,T) = edges[i];
            U = find(U,leader);
            T = find(T,leader);
            
            if(U==T)
                return 1;
            
            merge(U,T,leader, conex);
        }
        
        return 0;
            
    }
};
