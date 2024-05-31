// https://neps.academy/br/exercise/57

#include <stdio.h>

int main(){

    short int N,M,i,j,i_inicial,j_inicial;
    
    scanf("%hd%hd",&N,&M);
    short int cave[N+2][M+2];

    for( i=0; i<N; i++)
        for( j=0; j<M; j++){
            scanf("%hd",&cave[i][j]);
            if(cave[i][j]==2){
                i_inicial=i;
                j_inicial=j;
            }
        }
    
    i=i_inicial;
    j=j_inicial;
    short int answer=1;
    
    while(cave[i][j]!=3){
       
        cave[i][j]=0;

        if(i!=0 && cave[i-1][j]!=0){
            i--;
            answer++;
            continue;
        }
        if(i!=(N-1) && cave[i+1][j]!=0){
            i++;
            answer++;
            continue;
        }
        if(j!=0 && cave[i][j-1]!=0){
            j--;
            answer++;
            continue;
        }
        if(j!=(M-1) && cave[i][j+1]!=0){
            j++;
            answer++;
            continue;
        }

        answer=1;
        i=i_inicial;
        j=j_inicial;
    }

    printf("%d", answer);

    return 0;
}
