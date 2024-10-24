// https://judge.beecrowd.com/en/problems/view/1973

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int N, *Farm, i,visitadas=0;
	long long unsigned int Sum=0;
	
	scanf("%d",&N);
	Farm= (int*) (calloc((N+10), sizeof(int)));
	
	for(i=1; i<=N; i++){
		scanf("%d", (Farm+i) );
		Sum+=Farm[i];
	}
	
	for(i=1; i<=N;){
		if( visitadas<i )
			visitadas=i;
			
		if(Farm[i]==0)
			break;
		
		Farm[i]--;
		Sum--;
		
		if((Farm[i]+1)%2==1)	
			i++;
		else
			i--;

	}
	
	printf("%d %llu\n",visitadas,Sum);
	
	free(Farm);
	return 0;
}
