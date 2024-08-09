// https://atcoder.jp/contests/abc365/tasks/abc365_c
// C - Transportation Expenses

#include <bits/stdc++.h>

#define int int64_t

int cost (int x, int N, int A[]);

int32_t main (){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N,M;
    std::cin>>N>>M;

    int A[N], value, sum=0, maiorA = 0;

    for(int i=0; i<N; ++i){
        std::cin>>A[i];
        sum+=A[i];
        maiorA = (maiorA<A[i])? A[i] : maiorA;
    }

    if(sum<=M){
        std::cout<<"infinite\n";
        return 0;
    }

    int menorX = 0, maiorX = maiorA, x;

    while(1){

        x = (menorX+maiorX)>>1;

        if(maiorX - menorX < 2){
            if(cost(maiorX, N, A)<=M)
                std::cout<<maiorX<<'\n';
            else std::cout<<menorX<<'\n';
            return 0;
        }

        value = cost(x,N,A);

        if(value <= M)
            menorX = x;
        else maiorX = x;

    }

    return 0;
}

int cost (int x, int N, int A[]){
    int value = 0;
    for(int i =0; i<N; ++i)
        value+=std::min(A[i],x);
    return value;
}
