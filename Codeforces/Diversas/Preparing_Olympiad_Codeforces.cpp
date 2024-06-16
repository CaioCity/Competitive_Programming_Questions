// https://codeforces.com/contest/550/problem/B
// Preparing Olympiad

#include <bits/stdc++.h>

int main() {

    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);

    int N,L,R,X;
    int pot=1,aux,menor,maior,total,ans=0;

    std::cin>>N>>L>>R>>X;
    
    for(int i=0; i<N; i++)
        pot*=2;
        
    bool* problems=(bool*)calloc(N,sizeof(bool));
    int* dif=(int*)calloc(N+2,sizeof(int));
    dif[N]=INT32_MAX, dif[N+1]=-10;

    for(int i=0;i<N; i++)
        std::cin>>dif[i];    
    
    pot--;
    while(pot>1){
        aux=pot--;
        menor=N,maior=N+1,total=0;
        for(int i=0; i<N; i++){
            problems[i]=aux&1;
            if(problems[i]){
                if(dif[maior]<dif[i])
                    maior=i;
                if(dif[menor]>dif[i])
                    menor=i;
                total+=dif[i];
            }
            aux=aux>>1;
        }

        if(total<=R && total>=L && X<=(dif[maior]-dif[menor]))
            ans++;            
    }

    std::cout<<ans<<'\n';

    return 0;
}
