// https://atcoder.jp/contests/abc356/tasks/abc356_b
// Nutrients

#include <stdio.h>

int main(){

    short int N,M;

    scanf("%hd %hd", &N, &M);

    int meta[M],aux;

    for(short int i=0; i<M; i++)
        scanf("%d",&meta[i]);    

    while(N--){
        for( short int i=0; i<M; i++){
            scanf("%d",&aux);
            meta[i]-=aux;
        }
    }

    for(int i=0; i<M; i++)
        if(meta[i]>0){
            printf("No\n");
            return 0;
        }

    printf("Yes\n");

    return 0;
}
