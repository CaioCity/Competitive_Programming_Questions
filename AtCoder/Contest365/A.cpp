// https://atcoder.jp/contests/abc365/tasks/abc365_a
// A - Leap Year

#include <bits/stdc++.h>

#define int int64_t

int32_t main (){

    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int Y;
    std::cin>>Y;

    if(Y%4 != 0 )
        std::cout<<365<<'\n';
    else{
        if(Y%400 == 0)
            std::cout<<366<<'\n';
        else if(Y%100 == 0)
            std::cout<<365<<'\n';
        else std::cout<<366<<'\n';
    }

    return 0;
}
