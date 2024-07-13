// https://atcoder.jp/contests/abc355/tasks/abc355_a
// Who Ate the Cake?

#include <bits/stdc++.h>

int main(){

    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    
    short int A,B;

    std::cin>>A>>B;

    if(A==B)
        std::cout<<"-1\n";
    else{
        std::set<int> V = {1,2,3};
        V.erase(A);
        V.erase(B);
        std::cout<<*V.begin();
    }

    return 0;
}
