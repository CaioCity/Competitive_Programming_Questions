// https://atcoder.jp/contests/abc356/tasks/abc356_a
// Subsegment Reverse

#include <stdio.h>

int main(){

    short int N,L,R;

    scanf("%hd %hd %hd", &N, &L, &R);

    for(short int i=1; i<=N; i++){
        if(i<L || i>R || R==L)
            printf("%d ",i);
        else if(i<R){
            for(short int j=R; j>=i; j--)
                printf("%d ", j);
            i=R;
        }
    }

    printf("\n");

    return 0;
}
