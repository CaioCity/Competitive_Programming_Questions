// https://neps.academy/br/exercise/237

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    int N;
    scanf("%d",&N);
    short int* V;
    V=(short int*)calloc((N+2),sizeof(short int));

    scanf("%hd",V);
    for(int i=1; i<N; i++){
        scanf("%hd",(V+i));
        if(i<N/2)
            V[i]+=V[i-1];
    }
    
    for(int i=N-2; i>=floor(N/2); i--)
        V[i]+=V[i+1];

    int i=(N/2)-1, j=N/2;
    if(V[i]<V[j])
        while(V[i]!=V[j] && j<(N-1)){
            V[j]=V[i]+(V[j]-V[j+1]);
            i++;
            j++;
        }
    else
        while(V[i]!=V[j] && i>0){
            V[i]=V[j]+(V[i]-V[i-1]);
            i--;
            j--;
        }

    printf("\n%d\n",j);

    return 0;
}
