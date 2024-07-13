// https://atcoder.jp/contests/abc357/tasks/abc357_a
// Sanitize Hands

#include <stdio.h>

int main(){

    short int N,M,i,aux;

    scanf("%hd%hd",&N,&M);

    for(i=0; i<N; i++){
        scanf("%hd",&aux);
        M-=aux;
        if(M<0){
            printf("%hd\n",i);
            return 0;
        }
    }

    printf("%hd\n",N);

    return 0;
}
