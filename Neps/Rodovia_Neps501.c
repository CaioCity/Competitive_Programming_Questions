// https://neps.academy/br/exercise/501

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    short int N,A,B;
    scanf("%hd",&N);

    short int* V;
    bool* visita;
    V=(short int*)calloc(N+5, sizeof(short int));
    visita=(bool*)calloc(N+5, sizeof(bool));

    for(short int i=1; i<=N; i++){
        scanf("%hd%hd",&A,&B);
        if(V[A]!=0){
            printf("N\n");
            return 0;
        }
        V[A]=B;
    }
    
    for(short int i=0,aux=1; i<N; i++){
        visita[V[aux]]=1;
        aux=V[aux];
    }
    
    for(short int i=1; i<=N; i++)
        if(visita[i]==0){
            printf("N\n");
            return 0;
        }

    printf("S\n");

    free(V);
    free(visita);
    
    return 0;
}
