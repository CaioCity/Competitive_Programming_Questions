https://neps.academy/br/exercise/520

#include <iostream>
#include <vector>
#include <queue>

#define alcance(i,j) (bool)( (((cipos[i].x)-(cipos[j].x))*((cipos[i].x)-(cipos[j].x)))+(((cipos[i].y)-(cipos[j].y))*((cipos[i].y)-(cipos[j].y))) <= (range*range))
typedef struct {
	short int x, y;
	bool visited;
}triade;

int main(){

	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	short int N, range, cont=0;
	std::cin>>N>>range;
	
	std::vector <triade> cipos;
	std::queue <short int> visite;
	
	for(short int i=0; i<N; i++){
		short int x,y;
		std::cin>>x>>y;
		triade aux={x,y,0};
		cipos.push_back(aux);
	}
	
	visite.push(0);
	
	while(!(visite.empty())){
		short int i=visite.front();
		visite.pop();
		if(cipos[i].visited)
			continue;
		cont++;
		cipos[i].visited=1;
		for(short int j=0; j<N; j++)
			if(alcance(i,j) && i!=j)
				visite.push(j);
	}
	
	(cont==N)? std::cout<<"S" : std::cout<<"N";
	std::cout<<std::endl;
    
	return 0;
}
