// https://atcoder.jp/contests/abc351/tasks/abc351_c
// Merge the balls

#include <iostream>
#include <math.h>
#include <vector>

std::vector <int> V;

void operation (int i);

int main(){
	
	int N;	
	double A;
	
	std::cin>>N;
	
	for(int i=0; i<N; i++){
		std::cin>>A;		
		V.push_back(A); 
		operation(V.size()-1);
	}
	
	std::cout<<V.size()<<std::endl;
	
	return 0;
}

void operation(int i){
		if(V[i]==V[i-1] && V.size()>1){
			V.pop_back();
			V[i-1]+=1;
			operation(i-1);
		}	
}
