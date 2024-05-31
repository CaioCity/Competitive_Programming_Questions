// https://neps.academy/br/exercise/55

#include <stdio.h>

int main(){

    short int A=0,B=1,C=2,AB=3,AC=4,BC=5,G=6,SA=7,SB=8,SC=9; 
    short int N,V[11];

    scanf("%d",&N);
    for(short int i=0; i<7; i++)
        scanf("%d",V+i);

    
    V[SA]= V[A]-(V[AB]+V[AC]);
    V[SB]= V[B]-(V[AB]+V[BC]);
    V[SC]= V[C]-(V[BC]+V[AC]);

    if( (V[SA]+V[SB]+V[SC]+V[AB]+V[AC]+V[BC]+V[G]) != N )
        printf("S\n");
    else printf("N\n");

    return 0;
}
