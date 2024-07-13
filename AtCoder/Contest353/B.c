// https://atcoder.jp/contests/abc353/tasks/abc353_b
// AtCoder Amusement Park

#include <stdio.h>

int main (){

    short int N,K;
    scanf("%hd%hd", &N,&K);

    short int vezes=1,seats=K,Queue[N+5];

    for(short int i=0; i<N; i++){
        scanf("%hd",&Queue[i]);
        if( Queue[i] > seats ){
            vezes++;
            seats=K;
        }
        seats-=Queue[i];
    }
    
    printf("%hd\n",vezes);

    return 0;
}
