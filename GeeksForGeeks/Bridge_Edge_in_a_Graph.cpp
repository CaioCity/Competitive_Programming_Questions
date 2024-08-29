// https://www.geeksforgeeks.org/problems/bridge-edge-in-graph/1
// Bridge edge in a graph

class Solution
{
	public:
	int find (int A, int leader[]){
	    if(A==leader[A])
	        return A;
	    return leader[A]=find(leader[A],leader);
	}
	
	void join(int A, int B, int leader[], int conex[]){
	    if(conex[A]>conex[B])
	        swap(A,B);
	    leader[B] = leader[A];
	    conex[A]+=conex[B];
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d){
        int a,b;
        int *leader1 = (int*)malloc((V+2)*sizeof(int)), *conex1 = (int*)calloc(V+3,sizeof(int));
        int *leader2 = (int*)malloc((V+2)*sizeof(int)), *conex2 = (int*)calloc(V+3,sizeof(int));
        
        for(int i=0; i<V; ++i)
            leader1[i]=i;
        
        for(int i=0; i<V;++i)
            for(int T : adj[i]){
                a = find(i,leader1);
                b = find(T,leader1);
                if(a!=b)
                    join(a,b,leader1,conex1);
            }
            
        unordered_set<int> conexInicial;
        
        for(int i=0; i<V; ++i)
            conexInicial.insert(find(leader1[i],leader1));
            
        for(int& T : adj[c])
            if(T==d)
                T=c;
        for(int& T : adj[d])
            if(T==c)
                T=d;        
        
        for(int i=0; i<V; ++i)
            leader2[i]=i;
        
        for(int i=0; i<V;++i)
            for(int T : adj[i]){
                a = find(i,leader2);
                b = find(T,leader2);
                if(a!=b)
                    join(a,b,leader2,conex2);
            }
        
        unordered_set<int> conexFinal;
        
        for(int i=0; i<V; ++i)
            conexFinal.insert(find(leader2[i],leader2));
        
        return conexFinal.size()!=conexInicial.size();
    }
};
