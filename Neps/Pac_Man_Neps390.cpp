// https://neps.academy/br/exercise/390

#include <iostream>
#include <vector>

int main(){
	
	short int N, food=0, maior_food=0;
	std::cin>>N;
	
	char Tab[N][N];
	
	for(short int i=0; i<N; i++)
		for(short int j=0; j<N; j++)
			std::cin>>Tab[i][j];
			
	short int i=0,j=1;	
		
	while(i<N){
		
		if(i%2==0)			
			for(j=0; j<N; j++){			
				if(Tab[i][j]=='o')
					food++;
				else if(Tab[i][j]=='A'){
					maior_food= (maior_food>food)? maior_food : food;
					food=0;
				}
			}	
			
		else
			for(j=(N-1); j>=0; j--){
				if(Tab[i][j]=='o')
					food++;
				else if(Tab[i][j]=='A'){
					maior_food= (maior_food>food)? maior_food : food;
					food=0;
				}
			}
				
		i++;
	}
	
	maior_food= (maior_food>food)? maior_food : food;
	std::cout<<maior_food<<std::endl;
	
	return 0;
}
