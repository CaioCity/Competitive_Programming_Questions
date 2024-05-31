// https://neps.academy/br/exercise/394

#include <bits/stdc++.h>

bool binary_search(int, short int, short int, int*);

bool eh_soma (short int, int, int*);

int main(){
	
	std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	
	short int N, M;
	std::cin>>N>>M;
	
	int A[N],B[M];
	
	for(short int i=0; i<N; i++)
		std::cin>>A[i];

	std::sort(A,A+N);
	
	int aux;
	std::vector <int> lista;
	for(short int i=0; i<M; i++){
		std::cin>>aux;
		B[i]=aux;
		
		if(!binary_search( aux, 0, N, A))
			lista.push_back(aux);
	}
	    
    std::sort(B, B+M);
    
    short int tam_lista=lista.size();
    
    for(short int i=0; i<tam_lista; i++)
    	if(!eh_soma(M,lista[i], B)){
    		std::cout<<lista[i]<<std::endl;
    		return 0;
		}
    	
	
    
	std::cout<<"sim\n";
			
	return 0;			
}

bool binary_search (int target, short int inicio, short int fim, int* V){
	
	int meio= (inicio+fim)/2;
	
	if((fim-inicio)<2) {
		if ( V[fim]==target || V[inicio]==target )
			return 1;
		else
			return 0;
	}
		
	if(V[meio]==target)
		return 1;
	
	if(V[meio]>target)
		return binary_search (target, inicio, meio-1, V);
		
	if(V[meio]<target)
		return binary_search (target, meio+1, fim, V);

    return 0;
}

bool eh_soma (short int M,int target, int*B){

	short int j=M-1;
			
	for (short int i=0; i<=j;){
		if(target==(B[i]+B[j]))
			return 1;
		else if(target<(B[i]+B[j]))
			j--;
		else if(target>(B[i]+B[j]))
			i++;
	}
	
	return 0;
}
