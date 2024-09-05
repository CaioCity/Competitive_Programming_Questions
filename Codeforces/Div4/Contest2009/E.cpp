// https://codeforces.com/contest/2009/problem/E
// E - Klee's SUPER DUPER LARGE Array!!!

#include <bits/stdc++.h>

#define int int64_t
#define DEBUG(x) std::cout<<#x<<" = "<<x<<'\n';
const int INF = 1ll<<55;

int f(int x, int N, int K){
    int p1 = K*x + ((x*(x-1))>>1); 
    int p2 = K*(N-x) + (((N-1+x)*(N-x))>>1);
    return p1-p2;
}

int bs(int inicio, int fim, int N, int K){

    if(fim - inicio <2){
        if( f(fim,N,K) < 0 )
            return fim;
        return inicio;
    }

    int meio = (inicio + fim)>>1;
    int fmeio = f(meio,N,K);

    if(fmeio == 0)
        return meio;
    if(fmeio<0)
        return bs(meio,fim,N,K);
    return bs(inicio,meio,N,K);

}

void solve(){
   
    int N,K;
    std::cin>>N>>K;

    int index = bs(0,N-1,N,K);

    std::cout<<std::min(std::abs(f(index,N,K)), f(index+1,N,K))<<'\n';

    return;
}

int32_t main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int t;
    std::cin>>t;

    while(t--)
        solve();

    return 0;
}
