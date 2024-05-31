// https://neps.academy/br/exercise/56

#include <stdio.h>

int main(){

    int N,abrindo=0,abortar=0;
    char c;
    scanf("%d ",&N);

    while(N){
        
        scanf("%c",&c);

        if (c=='{') abrindo++;
        else if (c=='}') {
            if(abrindo==0) abortar=1;
            else abrindo--; 
        } 
        else if(c=='\n') N--;

        if(abortar){
            printf("N\n");
            return 0;
        }
        
    } 

    printf("%c\n", (abrindo==0)?'S':'N');

    return 0;
}
