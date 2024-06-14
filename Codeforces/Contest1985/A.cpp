// https://codeforces.com/contest/1985/problem/A
// Creating Words

#include <stdio.h>
#include <stdlib.h>

void build_crivo(int max, int* crivo);

int main(){

    short int N;
    char a,b,c,d,e,f;

    scanf("%hd",&N);

    for(short int i=0; i<N; i++){
        scanf(" %c %c %c %c %c %c", &d,&b,&c,&a,&e,&f);
        printf("%c%c%c %c%c%c\n",a,b,c,d,e,f);
    }
    
    return 0;
}
 
