// https://neps.academy/br/exercise/392

#include <bits/stdc++.h>

int main(){
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	short int N,M,next;
	bool mudar=0;
	std::cin>>N>>M;
	
	int Matriz[N][M];
	for(int i=0; i<N; i++)
		for( int j=0; j<M; j++)
			std::cin>>Matriz[i][j];
		
	for(int i=0; i<N; i++){
		for( int j=0; j<M; j++){
			
			if(Matriz[i][j]!=0){
				for(short int index=i+1; index<N; index++){
					if(Matriz[index][j]!=0){
						std::cout<<"N\n";
						return 0;
					}
				}
				break;
			}
			if(j==(M-1))
				mudar=1;
		} 
		if(mudar){
			next=i+1;
			break;
		}
	}
	
	if(mudar){
		for(int i=next; i<N; i++){
			for(int j=0; j<M; j++){
				if(Matriz[i][j]!=0){
					std::cout<<"N\n";
					return 0;
				}
			}
		}
	}
	
	std::cout<<"S\n";
	
	return 0;	
}
