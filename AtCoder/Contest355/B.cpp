// https://atcoder.jp/contests/abc355/tasks/abc355_b
// Piano 2

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    short int N,M;
    bool lastA=0;

    std::cin>>N>>M;

    short int A[N],B[M];

    for(short int i=0; i<N; i++)
        std::cin>>A[i];
        
    for(short int i=0; i<M; i++)
        std::cin>>B[i];

    std::sort(A,A+N);
    std::sort(B,B+M);

    int i,j;
    for( i=0,j=0; i<N && j<M; ){
        if(A[i]<B[j]){
            if(lastA){
                std::cout<<"Yes\n";
                return 0;
            }
            lastA=1;
            i++;
        } else {
            lastA=0;
            j++;
        }
    }

    if(i<=(N-2) && j==M)
        std::cout<<"Yes\n";
    else 
        std::cout<<"No\n";

    return 0;
}
