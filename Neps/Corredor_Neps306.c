// https://neps.academy/br/exercise/306

#include <stdio.h>
#include <stdlib.h>

int main(){

    int N,aux=0,maior=0;
    short int *V;

    scanf("%d",&N);

    V=(short int*)calloc(N+5,sizeof(short int));

    for(int i=0; i<N; i++){
        scanf("%hd",&V[i]);
        aux+=V[i];
        if(aux > maior)
            maior=aux;
        else if (aux<0)
            aux=0;
    }
        
    printf("%d\n",maior);

    return 0;
}
