// https://judge.beecrowd.com/en/problems/view/1024

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

bool eh_letra (char);

int main(){
	
	int N;
	register int i,j;
	float tam;
	char S[1010],a;
	
	scanf("%d", &N);
	
	for(i=0; i<N; i++){
		scanf(" %[^\n]", S);
		tam=strlen(S);
		for(j=tam; j>0; j--){
			printf("%c", (!eh_letra(S[j-1])? (j<=ceil(tam/2)? S[j-1]-1 : S[j-1]) : (j<=ceil(tam/2)? S[j-1]+2 : S[j-1]+3)));
		}
		putchar('\n');
	}	
	
	return 0;
}

bool eh_letra (char x){
	if((x>='A' && x<='Z')||(x>='a' && x<='z')) return true;
	return false;
}
