// https://atcoder.jp/contests/abc358/tasks/abc358_b
// Ticket Counter

#include <bits/stdc++.h>

int main() {

    std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);

    int N,A;
    int acumulado;
    std::cin>>N>>A;

    int time[N];

    std::cin>>acumulado;
    std::cout<<acumulado+A<<'\n';
   
    for(int i=1; i<N; i++){
        std::cin>>time[i];
        if(acumulado+A<=time[i]){
            std::cout<<time[i]+A<<'\n';
            acumulado=time[i];
        }
        else{
            std::cout<<acumulado+A+A<<'\n';
            acumulado+=A;
        }
    }

    return 0;
}
