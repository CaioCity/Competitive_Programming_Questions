// https://atcoder.jp/contests/abc361/tasks/abc361_a
// Insert

    #include <bits/stdc++.h>

    int main(){

        std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);


        int N,K,X,aux;
        std::cin>>N>>K>>X;

        for(int i=0;i<K; ++i){
            std::cin>>aux;
            std::cout<<aux<<' ';
        }

        std::cout<<X<<' ';

        for(; K<N; ++K){
            std::cin>>aux;
            std::cout<<aux<<' ';
        }

        std::cout<<'\n';

        return 0;
    }
