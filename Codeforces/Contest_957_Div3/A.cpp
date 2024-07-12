// https://codeforces.com/contest/1992/problem/A
// Only Pluses

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);

    int t,a,b,c,aux;

    std::cin>>t;

    while(t--){

        std::cin>>a>>b>>c;

        std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
        heap.push(a);
        heap.push(b);
        heap.push(c);

        for(int i=0; i<5; ++i){
            aux=heap.top();
            heap.pop();
            ++aux;
            heap.push(aux);
        }

        aux=1;
        for(int i=0; i<3; ++i){
            aux*=heap.top();
            heap.pop();
        }
        std::cout<<aux<<'\n';
    }


    return 0;
}
