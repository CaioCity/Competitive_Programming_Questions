// https://neps.academy/br/exercise/502

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

short int L,C;

void segue_teu_rumo (short , short , short C, bool [][C]);

int main(){

    short int A,B;
    scanf("%hd%hd%hd%hd",&L,&C,&A,&B);
    
    bool V[L+2][C+2];
    for(short int i=1; i<=L; i++)
        for(short int j=1; j<=C; j++)
            scanf("%d",&V[i][j]);        
        
    segue_teu_rumo(A,B,C, V);

    return 0;
}

void segue_teu_rumo (short int X, short int Y, short int C, bool V[][C+2] ){
    
    V[X][Y]=0;
    
    if(Y!=1)
        if(V[X][Y-1]==1)
            return segue_teu_rumo(X,Y-1,C,V);
    
    if(Y!=C)
        if(V[X][Y+1]==1)
            return segue_teu_rumo(X,Y+1,C,V);

    if(X!=1)
        if(V[X-1][Y]==1)
            return segue_teu_rumo(X-1,Y,C,V);

    if(X!=L)
        if(V[X+1][Y]==1)
            return segue_teu_rumo(X+1,Y,C,V);

    printf("%hd %hd\n",X,Y);
    
    return;

}
