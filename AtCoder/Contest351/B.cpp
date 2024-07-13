// https://atcoder.jp/contests/abc351/tasks/abc351_b
// Spot the Difference

#include <iostream>
#include <stdlib.h>

int main() { 
	
    unsigned short int N,idiff,jdiff;
    
    std::cin>>N;
    
    char A[N][N], B[N];
    
    for(int i=0; i<N; i++){
    	for(int j=0; j<N; j++)
    		scanf(" %c",&A[i][j]);
    }	

    for(int i=0; i<N; i++){
		scanf(" %s",B);
    	for(int j=0; j<N; j++){	
    		if(B[j]!=A[i][j]){
    			idiff=i;
    			jdiff=j;
			}
		}
    }
    
    std::cout<<idiff+1<<" "<<jdiff+1<<std::endl;
 	
    return 0;
}
