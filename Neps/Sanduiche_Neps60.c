// https://neps.academy/br/exercise/60

#include <stdio.h> 
#include <stdlib.h>

int main(){

    int N,D,sum=0;
    unsigned long long int answer=0;
    scanf("%d%d",&N,&D);

    short int*V=(short int*)calloc(N,sizeof(short int));

    for(int i=0; i<N; i++)
        scanf("%hd",V+i);  

    if(V[0]==D)
        answer++;  

    for(int i=0,j=0; j<N; j++){ //caso eu coma pedacos em sequencia
        
        if(V[j]>=D){
            if(V[j]==D)
                answer++;
            i=j+1;
            sum=0;
            continue;
        }
        
        sum+=V[j];
        
        if(sum==D){
            answer++;
            sum-=V[i];
            i++;
        }
        else if (sum > D){
            sum-=(V[i]+V[j]);
            i++;
            j--;//cancela o incremento
        }
    }

    if(V[N-1]<=D){//comendo pelas beiradas
        sum=V[N-1];
        int index;

        for(index=0; sum<D && index<(N-1); index++)
            sum+=V[index];
        if(sum==D)
            answer++;
        
        index--;
        sum+=V[N-2];
        if(sum==D)
            answer++;
        for(int j=N-2; index>=0 && j>0; j--){
            
            if(sum>D){
                sum-=V[index];
                index--;
                j++; //cancela o decremento
            }
            else if (sum==D && j>index){
                answer++;
                sum+=V[j-1];
            }
            else /*sum<D*/
                sum+=V[j-1];
            
        }
    }

    printf("%llu\n",answer);

    free(V);
    return 0;
}
