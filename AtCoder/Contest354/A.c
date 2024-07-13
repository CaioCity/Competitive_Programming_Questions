// https://atcoder.jp/contests/abc354/tasks/abc354_a
// Exponential Plant

    #include <stdio.h>  

    int main(){

        int H,pot=2,i=1;
        long long int planta=1;
        scanf("%d",&H);

        while(planta<=H){   
            planta+=pot;
            pot*=2;
            i++;
        }

        printf("%d\n",i);

        return 0;
    }
