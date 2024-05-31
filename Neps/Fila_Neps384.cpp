// https://neps.academy/br/exercise/384

#include <bits/stdc++.h>

bool binary_search (int, int, int, int*);

int main(){
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	int N,M;
	std::cin>>N;
	
	int Fila[N];
	for(int i=0; i<N; i++)
		std::cin>>Fila[i];
		
	std::cin>>M;
	int saiu[M];
	for(int i=0; i<M; i++)
		std::cin>>saiu[i];
	std::sort(saiu, saiu+M);
		
	for(int i=0; i<N; i++){
		bool esse_saiu= binary_search(Fila[i], 0, M-1, saiu);
		if(esse_saiu)
			Fila[i]=0;
	}
	
	int qnts_na_fila=N-M-1;
	int i;
	for(i=0; qnts_na_fila; i++)
		if(Fila[i]){
			std::cout<<Fila[i]<<" ";
			qnts_na_fila--;
		}
			
	for(; i<N; i++){
		if(Fila[i]!=0){
			std::cout<<Fila[i]<<std::endl;
			return 0;
		}
	}
	
	return 0;
}

bool binary_search (int target, int inicio, int fim, int* V){
	
	int meio= (inicio+fim)/2;
	
	if( (fim-inicio)<2 ){
		if( target==V[inicio] || target ==V[fim] )
			return 1;
		else 
			return 0;
	}
	
	if(target==V[meio])
		return 1;
	
	if(target<V[meio])
		return binary_search(target,inicio, meio-1, V);
	
	if(target>V[meio])
		return binary_search(target, meio+1,fim, V);
		
}
