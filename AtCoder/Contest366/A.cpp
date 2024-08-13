// https://atcoder.jp/contests/abc366/tasks/abc366_a
// A - Election 2

#include <bits/stdc++.h>

#define int int64_t

int32_t main (){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int N,T,A,falta;

    std::cin>>N>>T>>A;

    falta = N-T-A;

    if(abs(T-A) <= falta)
        std::cout<<"No\n";
    else std::cout<<"Yes\n";

    return 0;
}
