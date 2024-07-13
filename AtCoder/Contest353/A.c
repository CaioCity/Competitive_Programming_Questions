// https://atcoder.jp/contests/abc353/tasks/abc353_a
// Buildings

#include <stdio.h>

int main (){

    short int N;
    scanf("%hd", &N);

    short int V[N+5];

    for(short int i=0; i<N; i++){
        scanf("%hd",&V[i]);
        if(V[i]>V[0]){
            printf("%hd\n", i+1);
            return 0;
        }
    }
    
    printf("-1\n");
    
    return 0;
}
