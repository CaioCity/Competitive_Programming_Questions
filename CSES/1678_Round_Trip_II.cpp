// https://cses.fi/problemset/task/1678/
// Round Trip II

#include <bits/stdc++.h>
#include <stdint.h>
 
#define int int64_t
 
const int VISITED = 1, VISITING = 2;
 
// Retorna 1 se tiver ciclo, 0 caso contrario
bool dfs(int curr, int last[], int status[], std::vector<std::vector<int>>& edges){
	if(status[curr]==VISITING){
        int tam=2;
        int past = last[curr];
        while(past!=curr){
			++tam;
            past = last[past];
		}
		std::cout<<tam<<'\n';
		// codar recCycle
		std::cout<<curr+1<<' '; 
		past = last[curr];
		while(past!=curr){
			std::cout<<past+1<<' ';
			past = last[past];
		}
		std::cout<<curr+1<<'\n';
 
		return 1;
	}
 
	if(status[curr]==VISITED)
		return 0;
	
	status[curr] = VISITING;
	for(int T,i=0,tam=edges[curr].size(); i<tam; ++i){
		T = edges[curr][i];
		last[T]=curr;
		if(dfs(T,last,status,edges))
			return 1;
	}
		
	status[curr] = VISITED;
	return 0;
}
 
int32_t main(){
	
	std::ios::sync_with_stdio(0), std::cin.tie(0);
 
	int N,M,U,V;
	std::cin>>N>>M;
 
	int last[N], *status = (int*)calloc(N, sizeof(int));
	std::vector<std::vector<int>> edges (N,std::vector<int>(0));
 
	for(int i=0; i<M; ++i){
		std::cin>>U>>V;
		--U; --V;
		edges[V].push_back(U);
        // Invertendo o grafo para facilitar a extracao do caminho com last
	}
 
	for(int i=0; i<N; ++i)
		if(!status[i] && dfs(i,last,status,edges))
			return 0;
			
	std::cout<<"IMPOSSIBLE\n";
 
	return 0;
}
