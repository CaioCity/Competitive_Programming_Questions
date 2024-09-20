// https://www.geeksforgeeks.org/problems/topological-sort/1
// Topological Sort

// Solution with BFS
class Solution{
    public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<int> in_degree (V,0);
	    vector<int> ans;
	    queue<int> QU;
	    int U;
	    
	    for(int i=0; i<V; ++i)
	        for(int T : adj[i])
	            ++in_degree[T];
	            
	    for(int i=0; i<V; ++i)
	        if(in_degree[i]==0)
	            QU.push(i);
	   
	   while(!QU.empty()){
	        U = QU.front();
	        QU.pop();
	       
	        ans.push_back(U);
	        
	        for(int T : adj[U])
	            if(--in_degree[T]==0)
	                QU.push(T);
	   }
	  
	   if(ans.size()==V) return ans;
	   return vector<int>(0); 
	}
};

// Solution with DFS

vector<int> order, vis;
void dfs(int cur, vector<int> adj[]) {
    vis[cur] = true;
    for(auto child : adj[cur]) {
        if (vis[child]) continue;
        dfs(child, adj);
    }
    order.push_back(cur);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vis.resize(V, 0);
    for(int i = 0; i < V; ++i) {
        if (!vis[i]) {
            dfs(i, adj);
        }
    }
    
    reverse(order.begin(), order.end());
    return order;
}
