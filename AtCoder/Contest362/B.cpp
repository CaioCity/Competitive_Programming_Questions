// https://atcoder.jp/contests/abc362/tasks/abc362_b
// Right Triangle

#include <bits/stdc++.h>

int main() {

    std::ios::sync_with_stdio(0); std::cout.tie(0), std::cin.tie(0);

    int X1,Y1,X2,Y2,X3,Y3,L1,L2,L3;
    std::cin>>X1>>Y1>>X2>>Y2>>X3>>Y3;

    L1 = (X2 - X1)*(X2 - X1)+(Y2 - Y1)*(Y2 - Y1);

    L2 = (X3 - X1)*(X3 - X1)+(Y3 - Y1)*(Y3 - Y1);

    L3 = (X2 - X3)*(X2 - X3)+(Y2 - Y3)*(Y2 - Y3);

    if(L1<L2)
        std::swap(L1,L2);
    if(L1<L3)
        std::swap(L1,L3);

    if(L1==(L2+L3))
        std::cout<<"Yes\n";
    else std::cout<<"No\n";

    return 0;
}
